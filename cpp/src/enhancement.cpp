#include "displayiq/enhancement.hpp"

namespace displayiq {

    cv::Mat ImageEnhancer::enhanceContrast(const cv::Mat& inputImage,
        double clipLimit,
        cv::Size tileGridSize) {
        if (inputImage.empty()) {
            throw std::invalid_argument("Input image is empty.");
        }

        cv::Mat gray;
        cv::cvtColor(inputImage, gray, cv::COLOR_BGR2GRAY);

        cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE(clipLimit, tileGridSize);
        cv::Mat enhancedGray;
        clahe->apply(gray, enhancedGray);

        cv::Mat result;
        cv::cvtColor(enhancedGray, result, cv::COLOR_GRAY2BGR);
        return result;
    }

} // namespace displayiq