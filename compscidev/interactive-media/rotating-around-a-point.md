# Rotating around a Point

Parts from Class:

```
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath> // for pow

using namespace std;
using namespace cv;

// OpenCV includes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp" // Required for drawing functions

cv::Mat image;Point p = Point(300, 400);
Point p = Point(300, 400);
double angle = 0;

void rotation(){
    // Apply a rotation matrix to the point p & draw it onto the image
    double r_data[3][3] = {{cos(angle), -sin(angle), 0}, {sin(angle), cos(angle), 0}, {0, 0, 1}};
    Mat R = Mat(3, 3, CV_64FC1);
    Mat p_mat = Mat(3, 1, CV_64FC1);
    p_mat.ptr<double>(0)[0] = p.x;
    p_mat.ptr<double>(1)[0] = p.y;
    p_mat.ptr<double>(2)[0] = 1.0;
    
    //Perform Rotation
    p_mat = R * p_mat;
    
    // Save the new position back to `p`.
    p.x = p_mat.ptr<double>(0)[0];
    p.y = p_mat.ptr<double(1)[0]
}




int main() {
    // Initialize the Image
    image = Mat(800, 1000, CV_8UC3);
    Scalar(255, 255, 0);
}
```
