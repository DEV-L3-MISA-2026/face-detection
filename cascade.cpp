#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
using namespace cv;

int main() {
    VideoCapture cap;

    // cascade model    
    CascadeClassifier face_cascade;
    face_cascade.load(
        "/usr/share/opencv2/haarcascades/haarcascade_frontalface_alt.xml"
    );
    
    int deviceID = 0;        // camera index
    int apiID = CAP_ANY;     // Autodetect API
    cap.open(deviceID, apiID);
    
    if (!cap.isOpened()) {
        std::cerr << "ERROR! Unable to open camera\n";
        return -1;
    }

    // Grab and process frames
    Mat frame, gray;
    std::vector<Rect> faces;

    for (;;) {
        cap.read(frame);  // Capture frame
        
        if (frame.empty()) {
            std::cerr << "ERROR! Blank frame grabbed\n";
            break;
        }

        // process face detection
        cvtColor(frame, gray, COLOR_BGR2GRAY);
        face_cascade.detectMultiScale(
            gray,
            faces,
            1.1,           // scaleFactor
            3,             // minNeighbors
            0,            // flags
            Size(30, 30)  // min size
        );

        // draw faces
        
        for (const Rect& face : faces)
        {
            rectangle(frame, face, Scalar(0, 255, 0), 2);
        }
        // Display frame
        imshow("Live", frame);
        if (waitKey(5) >= 0) break;
    }
    
    return 0;
}