#include "LibRawReader.hpp"

namespace btrgb {

LibRawReader::LibRawReader(LibRawReader::libraw_type method) {
    this->_method = method;
    this->_configLibRawParams();
}


LibRawReader::~LibRawReader() {
    this->_reader.recycle();
}


void LibRawReader::recycle() {
    this->_reader.recycle();
    this->_configLibRawParams();
    this->_width = -1;
    this->_height = -1;
    this->_depth = -1;
    this->_channels = -1;
}


void LibRawReader::_configLibRawParams() {
	libraw_output_params_t* opt = &( this->_reader.imgdata.params );
    switch(this->_method) {

        case UNPROCESSED:
            /* Keep as 16 bit. */
            opt->output_bps = 16;
            /* Do not use histogram brightness/color scaling */
            opt->no_auto_bright = 1;
            opt->no_auto_scale = 1;
            break;

        case PREVIEW:
            opt->output_bps = 8;
            opt->no_auto_bright = 0;
            opt->no_auto_scale = 0;
            opt->half_size = 1;
            break;

        default: throw std::logic_error("[LibRawReader] Invalid method.");
    }

    /* Do not subtract camera black level. */
    opt->user_black = 0;

    /* Linear */
    opt->gamm[0] = 1.0;
    opt->gamm[1] = 1.0;

    /* Bi-linear interpolation. */
    opt->user_qual = 0;

    /* Don't use white balance. */
    opt->use_camera_wb = 0;
    opt->use_auto_wb = 0;

    /* Don't use camera matrix if present. */
    opt->use_camera_matrix = 0;

    /* Use raw color space. */
    opt->output_color = 0;
}


void LibRawReader::open(std::string filename) {
    int error_code;

    /* Open the file. */
    error_code = this->_reader.open_file(filename.c_str());
    if(error_code) {
        this->recycle();
        throw ReaderFailedToOpenFile();
    }

    /* Unpack raw data into structures for processing. */
    error_code = this->_reader.unpack();
    if(error_code) {
        this->recycle();
        throw std::runtime_error("[LibRaw] Failed to unpack image.");
    }

    /* Post-process (configured by LibRawReader::configLibRawParams) */
    error_code = this->_reader.dcraw_process();
    if(error_code) {
        this->recycle();
        throw std::runtime_error("[LibRaw] Failed to process image.");
    }

    /* Get the format of the bitmap result. */
    this->_reader.get_mem_image_format(&_width, &_height, &_channels, &_depth);


}



void LibRawReader::copyBitmapTo(void* buffer, uint32_t size) {
    if( size < _width * _height * _channels * (_depth / 8) )
        throw std::logic_error("[LibRawReader] Buffer size is too small.");
    
    int stride = this->_width * this->_channels;
    int error_code = this->_reader.copy_mem_image(buffer, stride, false);
    
    if(error_code) 
        throw std::runtime_error("[LibRawReader] Failed to copy image to buffer.");
}


void LibRawReader::copyBitmapTo(cv::Mat im) {

    /* Get depth of image to create. */
    int cv_depth;
    switch(this->_depth) {
        case  8: cv_depth = CV_8U; break;
        case 16: cv_depth = CV_16U; break;
        default: throw std::runtime_error("[LibRawReader] Internal error.");
    }

    /* Initialize OpenCV Mat if needed. */
    im.create(_height, _width, CV_MAKETYPE(cv_depth, _channels));
    
    /* Copy LibRaw image data to OpenCV Mat. */
    int stride = _width * _channels * (_depth / 8);
    int error_code = this->_reader.copy_mem_image(im.data, stride, false);
    if(error_code) 
        throw std::runtime_error("[LibRawReader] Failed to copy image to buffer.");

}

}