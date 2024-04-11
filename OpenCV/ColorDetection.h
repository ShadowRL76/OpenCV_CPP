#pragma once
#include <opencv2/opencv.hpp>



void detectAndDrawContours(cv::Mat& frame, cv::Mat& hsvFrame, cv::CascadeClassifier handCascade);
void displayFrame(const std::vector<std::string>& cascadeFilePaths);

