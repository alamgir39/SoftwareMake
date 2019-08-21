
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;

#define DP_EPSILON_DENOMINATOR 20.0
#define CVCLOSE_ITR 1

void findConnectedComponents (
    cv::Mat& mask,
    int poly1_hull0,
    float perimScale,
    vector<cv::Rect>& bbs,
    vector<cv::Point>& centers){

    poly1_hull0=0;

    perimScale=4;

    cv::morphologyEx(mask, mask, cv::MORPH_OPEN, cv::Mat(), cv::Point(-1,-1), CVCLOSE_ITR);
    cv::morphologyEx(mask, mask, cv::MORPH_CLOSE, cv::Mat(), cv::Point(-1,-1), CVCLOSE_ITR);
   //cv::medianBlur(mask,mask,9);
   //cv::Rect* rect;
    cv::Mat maskfloodholes;
    mask.copyTo(maskfloodholes);
    cv::floodFill(maskfloodholes,cv::Point(0,0),UCHAR_MAX);

    //cv::floodFill(maskfloodholes,cv::Point(0,0),UCHAR_MAX, rect, cv::Scalar(60), cv::Scalar(200));
   // maskfloodholes.copyTo(mask);
	cv::bitwise_not(maskfloodholes,maskfloodholes);
	//cv::bitwise_or(mask,maskfloodholes,mask);
//
	cv::bitwise_or(mask,maskfloodholes,mask);
	cv::medianBlur(mask,mask,9);
	//cv::morphologyEx(mask, mask, cv::MORPH_OPEN, cv::Mat(), cv::Point(-1,-1), CVCLOSE_ITR);

//    vector< vector<cv::Point> > contours_all; // all contours found
//    vector< vector<cv::Point> > contours; // just the ones we want to keep
//
//    cv::findContours(mask,contours_all,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE);
//
//   // int poly1_hull0=1;
//   //cout<<" Contours_all"<<contours_all<<endl;
//
//    for(vector< vector<cv::Point> >::iterator c = contours_all.begin();c != contours_all.end();++c) {
//    // length of this contour
//    //
//    int len = cv::arcLength( *c, true );
//    cout<<" len= "<<len<<endl;
//    // length threshold a fraction of image perimeter
//    //
//    double q = (mask.rows + mask.cols) / DP_EPSILON_DENOMINATOR;
//
//    if( len >= q ) { // If the contour is long enough to keep...
//    vector<cv::Point> c_new;
//    if( poly1_hull0 )
//    { // If the caller wants results as reduced polygons...
//    cv::approxPolyDP( *c, c_new, len/20.0, true );
//    }
//    else
//    { // Convex Hull of the segmentation
//    cv::convexHull( *c, c_new );
//    }
//    contours.push_back(c_new );
//    }
//    }
//
//
//    int idx = 0;
//    cv::Moments moments;
//    cv::Mat scratch = mask.clone();
//    for(vector< vector<cv::Point> >::iterator c = contours.begin(); c != contours.end(); c++, idx++)
//
//    {
//    cv::drawContours( scratch, contours, idx, UCHAR_MAX, CV_FILLED );
//   scratch.copyTo(mask);
//// Find the center of each contour
//
//    moments = cv::moments( scratch, true );
//
//    cv::Point p;
//    p.x = (int)( moments.m10 / moments.m00 );
//    p.y = (int)( moments.m01 / moments.m00 );
////    centers.push_back(p);
////    bbs.push_back( cv::boundingRect(c) );
//    scratch.setTo( 0 );
//    }
//// PAINT THE FOUND REGIONS BACK INTO THE IMAGE
////
//    mask.setTo( 0 );
//    cv::drawContours( mask, contours, -1, UCHAR_MAX );

}
