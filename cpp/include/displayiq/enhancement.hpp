#ifndef DISPLAYIQ_ENHANCEMENT_HPP
#define DISPLAYIQ_ENHANCEMENT_HPP

#include <opencv2/opencv.hpp>

namespace displayiq {

    class ImageEnhancer {
    public:
        /**
         * Apply CLAHE contrast enhancement to a BGR image.
         * @param inputImage Input image in BGR format.
         * @param clipLimit Threshold for contrast limiting.
         * @param tileGridSize Size of grid for histogram equalization.
         * @return Enhanced image in BGR format.
         */
        static cv::Mat enhanceContrast(const cv::Mat& inputImage,
            double clipLimit = 2.0,
            cv::Size tileGridSize = cv::Size(8, 8));
    };

} // namespace displayiq

#endif // DISPLAYIQ_ENHANCEMENT_HPP
