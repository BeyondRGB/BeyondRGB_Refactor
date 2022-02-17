

#include "../header/ColorManagedCalibrator.h"

void ColorManagedCalibrator::execute(CallBackFunction func, btrgb::ArtObject* images) {
    func("Color Managed Calibration");
    
    btrgb::Image* art1;
    btrgb::Image* art2;
    RefData* ref_data;
    ColorTarget target1;
    ColorTarget target2;

    std::cout << "\n\nStarting Tests ColorMangedCalibrator\n\n";

    try {
        art1 = images->getImage("art1");
        art2 = images->getImage("art2");
        ref_data = images->get_refrence_data();
        target1 = this->get_target(images, art1);
        target2 = this->get_target(images, art2);
    }
    catch (const btrgb::ArtObj_ImageDoesNotExist& e) {
        func("Error: Flatfielding called out of order. Missing at least 1 image assignment.");
        return;
    }
    catch (const std::logic_error& e) {
        std::string error(e.what());
        func("Error: " + error);
    }
    ColorTarget targets[] = { target1, target2 };
    int row_count = target1.get_row_count();
    int col_count = target2.get_col_count();
    int channel_count = art1->channels();
    int target_count = std::size(targets);
    int mat_cols = row_count * col_count;
    int mat_rows = channel_count * target_count;
    cv::Mat patch_avgs(mat_rows, mat_cols , CV_8UC1);
    for (int target = 0; target < target_count; target++) {
        for (int chan = 0; chan < channel_count; chan++) {
            int i = 0;
            for (int row = 0; row < row_count; row++) {
                for (int col = 0; col < col_count; col++) {
                    double avg = targets[target].get_patch_avg(row, col, chan);
                    std::cout << "target_" << target + 1 << " (row: " << row << ", col : " << col << ") chan: " << chan << std::endl;
                    patch_avgs.data[chan, i] = avg;
                }
            }
        }
    }
    double avg1 = target1.get_patch_avg(4, 0, 1);
    double avg2 = target2.get_patch_avg(4, 0, 1);
    std::cout << "avg1: " << avg1 << " avg2: " << avg2 << std::endl;
    
    sleep_for(seconds(5));
}

ColorTarget ColorManagedCalibrator::get_target(btrgb::ArtObject* images, btrgb::Image* im) {
    double target_top_location;
    double target_bottom_location;
    double target_left_location;
    double target_right_location;
    //int target_width;
    //int target_height;
    int target_row_count;
    int target_col_count;

    try {
        target_top_location = images->getTargetInfo("top");
        target_bottom_location = images->getTargetInfo("bot");
        target_left_location = images->getTargetInfo("left");
        target_right_location = images->getTargetInfo("right");

        target_row_count = images->getTargetSize("row");
        target_col_count = images->getTargetSize("col");
    }
    catch (const btrgb::ArtObj_ImageDoesNotExist& e) {
        throw e;
    }
    catch (const std::logic_error& e) {
        throw e;
    }

    ColorTarget target(im, target_top_location, target_bottom_location, target_left_location, target_right_location, target_row_count, target_col_count);
   
    return target;
}