//
// Created by ThinkPad41 on 10/10/2021.
//


#include "../header/ImageProcessor.h"

ImageProcessor::ImageProcessor(const std::vector<std::shared_ptr<ImgProcessingComponent>> &components) {
    for(auto & component : components){
        this->components.push_back(component);
    }
}
void ImageProcessor::execute(CallBackFunction func, ArtObject* images) {
    this->callback_func = func;
    this->callback_func("Starting Image Processor");
    for(auto  & component : this->components){
        component->execute(std::bind(&ImageProcessor::my_callback, this, std::placeholders::_1), images);
    }
    this->callback_func("Image Processing Done!!!");
}

void ImageProcessor::my_callback(std::string str) {
    this->callback_func("ImageProcessor->" + str);
}
