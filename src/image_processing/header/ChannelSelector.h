//
// Created by ThinkPad41 on 10/10/2021.
//

#ifndef BEYOND_RGB_BACKEND_CHANNELSELECTOR_H
#define BEYOND_RGB_BACKEND_CHANNELSELECTOR_H


#include "ImgProcessingComponent.h"

class ChannelSelector : public ImgProcessingComponent{
public:
    void execute(callback func) override;
};


#endif //BEYOND_RGB_BACKEND_CHANNELSELECTOR_H
