#pragma once
#include <opencv2/opencv.hpp>

struct ColorRange {
    cv::Scalar lower;
    cv::Scalar upper;
};

void detectAndDrawContours(cv::Mat& frame, cv::Mat& hsvFrame,  cv::Scalar const& lowerColor, cv::Scalar const& upperColor);
void displayFrame(const ColorRange& colorRange);
void on_trackbar(int, void*);
