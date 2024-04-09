#include <iostream>
#include "ColorDetection.h"

const ColorRange GREEN_RANGE = { cv::Scalar(35, 40, 40), cv::Scalar(85, 255, 255) };
const ColorRange BLUE_RANGE = { cv::Scalar(90, 40, 40), cv::Scalar(150, 255, 255) };
const ColorRange RED_RANGE = { cv::Scalar(0, 120, 70), cv::Scalar(10, 255, 255) };

int main() {
    displayFrame(RED_RANGE);
    return EXIT_SUCCESS;
}
