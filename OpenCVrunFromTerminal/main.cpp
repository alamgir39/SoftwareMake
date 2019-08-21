#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<iostream>
#include "headerfunction.h"
using namespace std;
using namespace cv;

#define DP_EPSILON_DENOMINATOR 20.0
#define CVCLOSE_ITR 1

int main(int argc, char *argv[])
{
    cv::Mat m_defaultMorphologyKernel;
    m_defaultMorphologyKernel=cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::Mat img, img_edge, labels, img_color, stats, m_oFGMask_PreFlood, m_oFGMask_FloodedHoles;

     img = imread("foreground.png", 1);
     cvtColor(img,img,CV_BGR2GRAY);

    if(img.empty())
       return -1;
    cv::threshold(img, img, 200, 255, cv::THRESH_BINARY);
    vector<cv::Rect> bbs;
    vector<cv::Point> centers;
//    cv::morphologyEx(img, img, cv::MORPH_OPEN, cv::Mat(), cv::Point(-1,-1), CVCLOSE_ITR);
//    cv::morphologyEx(img, img, cv::MORPH_CLOSE, cv::Mat(), cv::Point(-1,-1), CVCLOSE_ITR);
    //cv::imshow("Thresholded Image ", img);

    cv::imshow("Gray Input Image ", img);

   // cv::morphologyEx(img, img, cv::MORPH_OPEN, m_defaultMorphologyKernel);
    //cv::morphologyEx(img, img, cv::MORPH_CLOSE, m_defaultMorphologyKernel);
     //erode( img, img, m_defaultMorphologyKernel);
    // cv::imshow("Eroded Image ", img);
    cv::medianBlur(img,img,9);
    cv::imshow("Median After Eroded Image ", img);
     //cv::morphologyEx(img, img, cv::MORPH_CLOSE, cv::Mat(), cv::Point(-1,-1), CVCLOSE_ITR);
     //cv::morphologyEx(img, img, cv::MORPH_CLOSE, m_defaultMorphologyKernel);
    //cv::medianBlur(img,img,9);

   // dilate( img, img, cv::MORPH_RECT );
    cv::Mat maskfloodholes;
    img.copyTo(maskfloodholes);

    cv::floodFill(maskfloodholes,cv::Point(0,0),UCHAR_MAX);
    cv::bitwise_not(maskfloodholes,maskfloodholes);
    cv::bitwise_or(img,maskfloodholes,img);
    //cv::morphologyEx(img,img,cv::MORPH_CLOSE, (3,3));
    cv::medianBlur(img,img,9);
    //dilate( img, img, m_defaultMorphologyKernel);
    cv::imshow("Processed Image ", img);


////    cv::floodFill(maskfloodholes,cv::Point(0,0),UCHAR_MAX);
////
////    cv::imshow("Thresholded Image ", maskfloodholes);
////
////    cv::bitwise_not(maskfloodholes,maskfloodholes);
////
////   // cv::imshow("Thresholded Image ", maskfloodholes);
////
////
////    cv::bitwise_or(img,maskfloodholes,img);
////	cv::medianBlur(img,img,9);

   // findConnectedComponents (img,1,4,bbs,centers);

    //cv::imshow("Thresholded Image ", img);



// vector<cv::Vec3b> colors(nccomps+1);
// colors[0] = Vec3b(0,0,0); // background pixels remain black.
// for( i = 1; i <= nccomps; i++ ) {
// colors[i] = Vec3b(rand()%256, rand()%256, rand()%256);
// if( stats.at<int>(i-1, cv::CC_STAT_AREA) < 100 )
// colors[i] = Vec3b(0,0,0); // small regions are painted with black too.
// }
// img_color = Mat::zeros(img.size(), CV_8UC3);
// for( int y = 0; y < img_color.rows; y++ )
// for( int x = 0; x < img_color.cols; x++ )
// {
// int label = labels.at<int>(y, x);
// CV_Assert(0 <= label && label <= nccomps);
// img_color.at<cv::Vec3b>(y, x) = colors[label];
// }
// cv::imshow("Labeled map", img_color);
//        cv::morphologyEx(img,m_oFGMask_PreFlood,cv::MORPH_CLOSE, (5,5));
//        m_oFGMask_PreFlood.copyTo(m_oFGMask_FloodedHoles);
//        cv::floodFill(m_oFGMask_FloodedHoles,cv::Point(0,0),UCHAR_MAX);
//       cv::bitwise_not(m_oFGMask_FloodedHoles,m_oFGMask_FloodedHoles);
//       cv::erode(m_oFGMask_PreFlood,m_oFGMask_PreFlood,(5,5),cv::Point(-1,-1),3);
//       cv::medianBlur(m_oFGMask_FloodedHoles,m_oFGMask_FloodedHoles,5);
//        cv::bitwise_or(img,m_oFGMask_FloodedHoles,img);
//
//        cv::bitwise_or(img,m_oFGMask_PreFlood,img);
//	     cv::medianBlur(img,img_edge,5);
//	cv::dilate(m_oLastFGMask,m_oLastFGMask_dilated,m_defaultMorphologyKernel,cv::Point(-1,-1),3);
//
//    cv::morphologyEx(img_edge,img_edge,cv::MORPH_CLOSE, (5,5));
//        cv::imshow("Origianl Image", m_oFGMask_FloodedHoles);
//        cv::imshow("Image after median", img_edge);
//     cv::imshow("Connected Comp ", labels);


    //namedWindow( "lena", CV_WINDOW_AUTOSIZE );
    //imshow("lena", img);
    waitKey(0);
    return 0;
}







