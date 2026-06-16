#include "FaceRecognizer.h"

namespace fr {
        FaceRecognizer::FaceRecognizer(cv::Ptr<FaceDetector> face_detector, std::string model_path, int backend_id, int target_id ) {
            this->face_detector = face_detector;
            this->face_recognizer = cv::FaceRecognizerSF::create(model_path, "", backend_id, target_id);
        }

        cv::Mat FaceRecognizer::GetCharacteristic(cv::Mat img) {
            cv::Mat faces = this->face_detector->GetMatFace(img);
            
            // SÉCURITÉ : Si la matrice est vide, on ne fait rien et on quitte proprement
            if (faces.empty()) {
                std::cerr << "Erreur : Impossible d'extraire les caractéristiques (aucun visage)." << std::endl;
                return cv::Mat(); 
            }

            cv::Mat aligned, features;
            
            // Maintenant row(0) est safe !
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

