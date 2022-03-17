#include <regex>
#include "backend_process/ThumbnailLoader.hpp"

unsigned int ThumbnailLoader::id = 0;

ThumbnailLoader::ThumbnailLoader() {
    this->set_process_name("ThumbnailLoader(" + std::to_string(ThumbnailLoader::id) + ")");
    ThumbnailLoader::id += 1;
}

ThumbnailLoader::~ThumbnailLoader() {}


void ThumbnailLoader::run() {

    Json filenames = this->process_data_m->get_array("names");

    std::unique_ptr<btrgb::LibRawThumbnail> raw_thumbnail_reader(new btrgb::LibRawThumbnail);
    std::unique_ptr<btrgb::TiffReaderOpenCV> tiff_reader(new btrgb::TiffReaderOpenCV);
    std::string fname;
        
    for (int i = 0; i < filenames.get_size(); i++) {
        try {

            fname = filenames.string_at(i);
            if(btrgb::Image::is_tiff(fname))
                this->_read_tiff(tiff_reader.get(), fname);
            else
                this->_read_raw_thumbnail(raw_thumbnail_reader.get(), fname);

        }
        catch(btrgb::ReaderFailedToOpenFile& e) {
            this->coms_obj_m->send_error("Failed to open file " + fname, "ThumbnailLoader");
            std::cerr << "Failed to open file " + fname << std::endl;
        }
        catch(std::runtime_error& e) {
            this->coms_obj_m->send_error(e.what(), "ThumbnailLoader");
            std::cerr << e.what() << std::endl;
        }
        catch(...) {
            this->coms_obj_m->send_error("[ThumbnailLoader] Unknown error.", "ThumbnailLoader");
            std::cerr << "[ThumbnailLoader] Unknown error." << std::endl;
        }

        raw_thumbnail_reader->recycle();
        tiff_reader->recycle();
    }
}


void ThumbnailLoader::_read_raw_thumbnail(btrgb::LibRawThumbnail* reader, std::string file) {
    reader->open(file);

    if( reader->is_encoded() ) {

        std::unique_ptr<std::vector<uchar>> binary(new std::vector<uchar>);
        reader->copyBitmapTo(*binary);
        reader->recycle();

        this->coms_obj_m->send_base64(file, binary.get(), btrgb::JPEG);
    }
    else {
        cv::Mat im;
        reader->copyBitmapTo(im);
        reader->recycle();

        /* Wrap the Mat as an Image object. */
        btrgb::Image imObj(file);
        imObj.initImage(im);

        /* The thumbnail is small so use btrgb::FULL, otherwise the thumbnails
            * will get upscaled to a width of 2000 pixels, wasting time and memory. */
        this->coms_obj_m->send_base64(&imObj, btrgb::PNG, btrgb::FULL);
    }
}

void ThumbnailLoader::_read_tiff(btrgb::TiffReaderOpenCV* reader, std::string file) {
    /* Open tiff. */
    reader->open(file);
    cv::Mat im( reader->height(), reader->width(), CV_8UC(reader->channels()) );
    reader->copyBitmapTo( (uint8_t*) im.data, im.rows * im.cols * im.channels() );
    reader->recycle();

    /* Wrap the Mat as an Image object. */
    btrgb::Image imObj(file);
    imObj.initImage(im);

    /* Send image. */
    this->coms_obj_m->send_base64(&imObj, btrgb::PNG, btrgb::FAST);
}