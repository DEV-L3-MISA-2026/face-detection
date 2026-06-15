#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;

int main() {
    VideoCapture cap;
    
    int deviceID = 0;        // camera index
    int apiID = CAP_ANY;     // Autodetect API
    cap.open(deviceID, apiID);
    
    if (!cap.isOpened()) {
        std::cerr << "ERROR! Unable to open camera\n";
        return -1;
    }
    
    // Grab and process frames
    Mat frame;
    for (;;) {
        cap.read(frame);  // Capture frame
        
        if (frame.empty()) {
            std::cerr << "ERROR! Blank frame grabbed\n";
            break;
        }
        
        // Display frame
        imshow("Live", frame);
        if (waitKey(5) >= 0) break;

        
    }
    
    return 0;
}