#include <iostream>
#include <opencv2/opencv.hpp>
#include "displayiq/enhancement.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./enhance <path_to_image>" << std::endl;
        return 1;
    }

    std::string imagePath = argv[1];
    cv::Mat img = cv::imread(imagePath);
    if (img.empty()) {
        std::cerr << "Error: Could not load image: " << imagePath << std::endl;
        return 1;
    }

    try {
        cv::Mat enhanced = displayiq::ImageEnhancer::enhanceContrast(img);
        cv::imshow("Original", img);
        cv::imshow("Enhanced", enhanced);
        cv::waitKey(0);
    }
    catch (const std::exception& e) {
        std::cerr << "Processing error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}