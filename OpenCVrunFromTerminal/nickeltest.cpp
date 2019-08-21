
//#include <opencv2/core/core.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include<iostream>

#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;
int main(int argc, char **argv)
{
    int lowThreshold = 0;
const int max_lowThreshold = 100;
const int ratio = 3;
const int kernel_size = 3;

    // Read image
    Mat im_in = imread("foreground.png", 1);

    //imshow("Original Input Image", im_in);

    // Threshold.
    // Set values equal to or above 220 to 0.
    // Set values below 220 to 255.
   Mat im_th;

   cvtColor(im_in, im_in, CV_BGR2GRAY);
  // threshold(im_in, im_th, 140, 255, THRESH_BINARY);
    imshow("Thresholded Image", im_th);

//    Mat detected_edges;
//     blur( im_in, detected_edges, Size(3,3) );
//     Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );
//     imshow("Canny Image", detected_edges);

    // Floodfill from point (0, 0)
    Mat im_floodfill = im_th.clone();
    floodFill(im_floodfill, cv::Point(0,0), Scalar(255));
    imshow("Floodfilled Image", im_floodfill);
////
//    // Invert floodfilled image
//    Mat im_floodfill_inv;
//    bitwise_not(im_floodfill, im_floodfill_inv);
//    imshow("Inverted Floodfilled Image", im_floodfill_inv);
////
//    // Combine the two images to get the foreground.
//    Mat im_out = (im_th | im_floodfill_inv);
//    imshow("Foreground", im_out);

    // Display images




    waitKey(0);

}
