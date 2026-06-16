#include "FaceDetector.h"
#include "FaceRecognizer.h"

#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>


int main() {
    std::string model_path = "../model/face_detection_yunet_2023mar.onnx";
    cv::Ptr<fr::FaceDetector> detector = cv::makePtr<fr::FaceDetector>(model_path, cv::Size(320, 320), 0.8, 0.4, fr::backend_target_pairs.at(0).first, fr::backend_target_pairs.at(0).second
    );

    model_path =  "../model/face_recognition_sface_2021dec.onnx";
    fr::FaceRecognizer face_recognizer(detector, model_path);
    cv::Mat img = cv::imread("../me.jpeg");
    
    cv::Mat test_faces = detector->GetMatFace(img);
    
    cv::Mat characteristic = face_recognizer.GetCharacteristic(img);

    int c = 0;
    for (int y = 0; y < characteristic.rows; ++y) {
        for (int x = 0; x < characteristic.cols; ++x) {
            std::cout << characteristic.at<float>(y, x) << " ";
            c++;
        }
    }
    
    return 0;
}