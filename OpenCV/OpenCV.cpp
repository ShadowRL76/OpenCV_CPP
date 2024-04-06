#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "ColorDetection.h" 


struct ColorRange {
    cv::Scalar lower;
    cv::Scalar upper;
};

const ColorRange BLUE_RANGE = { cv::Scalar(90, 40, 40), cv::Scalar(150, 255, 255) };

const ColorRange GREEN_RANGE = { cv::Scalar(35, 40, 40), cv::Scalar(85, 255, 255) };

const ColorRange RED_RANGE = { cv::Scalar(0, 120, 70), cv::Scalar(10, 255, 255) };

//TODO: Add more colors

void displayFrame(const ColorRange& colorRange) {
    cv::Mat frame;
    cv::Mat hsvFrame;
    cv::VideoCapture vcap(0);

    if (!vcap.isOpened()) {
        std::cerr << "Error: Unable to locate webcam." << std::endl;
        return;
    }
    do {
        vcap >> frame;

        if (!vcap.read(frame)) {
            std::cerr << "Error: Blank frame grabbed" << std::endl;
            break;
        }
        cv::cvtColor(frame, hsvFrame, cv::COLOR_BGR2HSV);

        detectAndDrawContours(frame, hsvFrame, colorRange.lower, colorRange.upper);

        cv::namedWindow("Webcam Feed", cv::WINDOW_NORMAL);
        cv::imshow("Webcam Feed", frame);
    } while (cv::waitKey(30) != 'q');

    cv::destroyAllWindows();
}

int main() {
    displayFrame(GREEN_RANGE);
    return EXIT_SUCCESS;
}
