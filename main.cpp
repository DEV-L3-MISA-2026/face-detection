#include "FaceDetector.h"

int main() {
    std::string model_path = "../model/face_detection_yunet_2023mar.onnx";
    fr::FaceDetector detector(
        model_path,
        cv::Size(320, 320), // kinda random
        1,
        1,
        fr::backend_target_pairs[0].first,
        fr::backend_target_pairs[0].second
    );

    cv::Mat img = cv::imread("../me.jpeg");
    cv::Mat result = detector.GetFace(img);

    cv::imwrite("../output.jpeg", result);

    return 0;
}