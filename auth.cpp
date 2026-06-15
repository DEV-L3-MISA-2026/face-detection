#include <opencv2/objdetect/face.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;



int main(int argc, char* argv) {
    Ptr<FaceDetectorYN> detector = FaceDetectorYN::create(
        "face_detection_yunet_2023mar.onnx",
        "",
        Size(320, 320)  // we will change it later
    );
    Mat img = imread("me.jpeg");
    detector->setInputSize(img.size());
    Mat faces;

    detector->detect(img, faces);

    for(int i = 0; i < faces.rows; i++)
    {
        float confidence = faces.at<float>(i, 14);
        if(confidence > 0.9)
        {
            int x = faces.at<float>(i, 0);
            int y = faces.at<float>(i, 1);
            int w = faces.at<float>(i, 2);
            int h = faces.at<float>(i, 3);
            rectangle(img, Rect(x, y, w, h),
                    Scalar(0, 255, 0), 2);
        }
    }
    return 0;
}