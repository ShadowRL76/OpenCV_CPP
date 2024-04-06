#pragma once
 
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

void detectAndDrawContours(cv::Mat& frame, cv::Mat& hsvFrame, cv::Scalar const& lowerColor, cv::Scalar const& upperColor){

    cv::Mat Mask;
    cv::inRange(hsvFrame, lowerColor, upperColor, Mask);
 
    std::vector<std::vector<cv::Point>> Contours;
    cv::Mat Hierarchy;
    cv::findContours(Mask, Contours, Hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
 
    for (const auto& Contour : Contours) {
        const double area = cv::contourArea(Contour);
        if (area > 5000) {
 
            const auto boundingRect = cv::boundingRect(Contour);

            cv::rectangle(frame, boundingRect, CV_RGB(255, 255, 0), 2);
 
            const double cX = boundingRect.x + boundingRect.width * 0.5;
            const double cY = boundingRect.y + boundingRect.height * 0.5;
 
            cv::circle(frame, cv::Point(cX, cY), 5, cv::Scalar(255, 0, 0), -1);
 
            std::string text = "X: " + std::to_string(cX) + ", Y: " + std::to_string(cY);
            cv::putText(frame, text, cv::Point(static_cast<int>(cX) + 10, static_cast<int>(cY) + 10), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 255), 2);

        }
    }
}
 