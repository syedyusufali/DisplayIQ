#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <opencv2/opencv.hpp>
#include "displayiq/enhancement.hpp"

namespace py = pybind11;

cv::Mat numpyToMat(py::array_t<uint8_t>& input) {
    py::buffer_info buf = input.request();
    int rows = buf.shape[0];
    int cols = buf.shape[1];
    int channels = buf.shape[2];

    return cv::Mat(rows, cols, CV_8UC3, buf.ptr);
}

py::array_t<uint8_t> matToNumpy(const cv::Mat& mat) {
    py::buffer_info info(
        mat.data,
        sizeof(uint8_t),
        py::format_descriptor<uint8_t>::format(),
        3,
        { mat.rows, mat.cols, mat.channels() },
        { static_cast<size_t>(mat.step[0]),
          static_cast<size_t>(mat.step[1]),
          sizeof(uint8_t) }
    );
    return py::array(info);
}

PYBIND11_MODULE(displayiq_cpp, m) {
    m.doc() = "C++ accelerated image enhancement using CLAHE";

    m.def("enhance_contrast", [](py::array_t<uint8_t> input, double clipLimit, int tileSize) {
        cv::Mat img = numpyToMat(input);
        cv::Mat result = displayiq::ImageEnhancer::enhanceContrast(img, clipLimit, cv::Size(tileSize, tileSize));
        return matToNumpy(result);
        }, py::arg("input"), py::arg("clip_limit") = 2.0, py::arg("tile_size") = 8);
}
