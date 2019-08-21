#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

#define CVCLOSE_ITR 1
int main( int argc, char** argv ) {

cv:: Mat g_gray  = imread("foreground.png", 1);
     cvtColor(g_gray ,g_gray ,CV_BGR2GRAY);
     cv::imshow("Gray Input Image ", g_gray );
    if(g_gray .empty())
       return -1;
cv::Mat g_binary;
    cv::threshold( g_gray, g_binary, 220, 255, cv::THRESH_BINARY );

//    cv::morphologyEx(g_binary, g_binary, cv::MORPH_OPEN, cv::Mat(), cv::Point(-1,-1), CVCLOSE_ITR);
//    cv::morphologyEx(g_binary, g_binary, cv::MORPH_CLOSE, cv::Mat(), cv::Point(-1,-1), CVCLOSE_ITR);
//    cv::imshow( "After Cleaning", g_binary );

//    thresh = cv2.erode(thresh, None, iterations=2)
//    thresh = cv2.dilate(thresh, None, iterations=4)
    vector< vector< cv::Point> > contours;
    vector< cv::Vec4i > hierarchy;
 cv::findContours(
 g_binary,
 contours,
 hierarchy,
 //cv::RETR_LIST,
 CV_RETR_EXTERNAL,
 cv::CHAIN_APPROX_SIMPLE
 );
 g_binary = cv::Scalar::all(0);
 cv::drawContours( g_binary, contours, -1, cv::Scalar::all(255));
 cv::imshow( "Contours", g_binary );

 cv::waitKey();
 return 0;
}
