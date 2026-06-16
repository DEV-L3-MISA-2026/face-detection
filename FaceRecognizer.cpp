#include "FaceRecognizer.h"

namespace fr {
        FaceRecognizer::FaceRecognizer(cv::Ptr<FaceDetector>, std::string model_path, int backend_id, int target_id ) {
            this->face_detector = face_detector;
            this->face_recognizer = cv::FaceRecognizerSF::create(model_path, "", backend_id, target_id);
        }

        cv::Mat FaceRecognizer::GetCharacteristic(cv::Mat img) {
            cv::Mat faces = this->face_detector->GetMatFace(img);
            cv::Mat aligned, features;
            face_recognizer->alignCrop(
                img, 
                faces.row(0),
                aligned
            );

            face_recognizer->feature(
                aligned, 
                features
            );
            return features;
        }



}

