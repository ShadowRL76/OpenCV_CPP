#include <iostream>
#include "ColorDetection.h"

const ColorRange GREEN_RANGE = { cv::Scalar(35, 40, 40), cv::Scalar(85, 255, 255) };

int main() {
    displayFrame(GREEN_RANGE);
    return EXIT_SUCCESS;
}
