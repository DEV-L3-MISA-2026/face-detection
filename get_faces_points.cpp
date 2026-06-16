#include <opencv2/opencv.hpp>
using namespace cv;
int main() {
    auto _recognizer = FaceRecognizerSF::create("../model/face_recognition_sface_2021dec.onnx", "", dnn::DNN_BACKEND_OPENCV, dnn::DNN_TARGET_CPU);
    return 0;
}