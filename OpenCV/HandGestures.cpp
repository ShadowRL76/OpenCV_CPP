#include <iostream>
#include <fstream>
#include "ColorDetection.h"


std::ofstream outfile;


void detectAndDrawContours(cv::Mat& frame, cv::Mat& hsvFrame, cv::CascadeClassifier handCascade) {
    std::vector<cv::Rect> hands;
    handCascade.detectMultiScale(frame, hands, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

    for (const auto& hand : hands) {
        cv::rectangle(frame, hand, cv::Scalar(255, 0, 0), 2);

        const double cX = hand.x + hand.width * 0.5;
        const double cY = hand.y + hand.height * 0.5;

        cv::circle(frame, cv::Point(cX, cY), 5, cv::Scalar(255, 0, 0), -1);

        std::string text = "X: " + std::to_string(cX) + ", Y: " + std::to_string(cY);
        cv::putText(frame, text, cv::Point(static_cast<int>(cX) + 10, static_cast<int>(cY) + 10), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 255), 2);
        
        cv::putText(frame, "Detected Hand", cv::Point(50, 50), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 2);

        std::ofstream outfile;

        outfile.open("opencvData.txt", std::ios::app);

        if (!outfile.is_open())
            return;

        outfile << text << std::endl;
    }
}



void displayFrame(const std::vector<std::string>& cascadeFilePaths) {
    cv::Mat frame;
    cv::VideoCapture vcap(0);
    const int delayInMilliseconds(30);

    if (!vcap.isOpened()) {
        std::cerr << "Error: Unable to locate webcam." << std::endl;
        return;
    }

    std::vector<cv::CascadeClassifier> handCascades;
    for (const auto& cascadeFilePath : cascadeFilePaths) {
        cv::CascadeClassifier handCascade;
        if (!handCascade.load(cascadeFilePath)) {
            std::cerr << "Error: Unable to load hand cascade file: " << cascadeFilePath << std::endl;
            return;
        }
        handCascades.push_back(handCascade);
    }

    cv::namedWindow("Webcam Feed", cv::WINDOW_NORMAL);

    do {
        vcap >> frame;

        if (!vcap.read(frame)) {
            std::cerr << "Error: Blank frame grabbed" << std::endl;
            break;
        }

        for (const auto& handCascade : handCascades) {
            detectAndDrawContours(frame, frame, handCascade);

        }


        cv::imshow("Webcam Feed", frame);

    } while (cv::waitKey(delayInMilliseconds) != 'q');

    cv::destroyAllWindows();
}