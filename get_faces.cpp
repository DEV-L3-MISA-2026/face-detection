#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <vector>
using namespace cv;

int main() {

    int width = 1200, height = 600;
    Mat img = imread("me.jpeg"), gray, cropped;
    std::vector<Rect> faces;

    CascadeClassifier face_cascade;
    face_cascade.load(
        "/usr/share/opencv2/haarcascades/haarcascade_frontalface_alt.xml"
    );

    cvtColor(img, gray, COLOR_BGR2GRAY);
        
        face_cascade.detectMultiScale(
            gray,
            faces,
            1.1,           // scaleFactor
            3,             // minNeighbors
            0,            // flags
            Size(30, 30)  // min size 
        );

    if(faces.size() == 0) {
        std:: cout << "no faces deteced !" << std::endl;
    }

    // adding some padding
    int padding_w = 100, padding_h = 200;
    Rect face = faces[0];

    face.width += padding_w;
    face.x -= padding_w/2; 
    face.height += padding_h;
    face.y -= padding_h/2;

    cropped = img(face).clone();
    imwrite("output.jpeg", cropped);
    return 0;
}