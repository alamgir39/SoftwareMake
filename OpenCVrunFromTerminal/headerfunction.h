using namespace std;
using namespace cv;

void findConnectedComponents (
    cv::Mat& mask,
    int poly1_hull0,
    float perimScale,
    vector<cv::Rect>& bbs,
    vector<cv::Point>& centers);

