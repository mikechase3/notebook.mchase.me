# Interactive Media



## Notes

<figure><img src="../../.gitbook/assets/CleanShot 2024-01-16 at 13.36.32@2x.png" alt=""><figcaption></figcaption></figure>

## 2024JAN16

* We learned important data structures: `mat` and `scalar`.
* `imread` takes stuff from the hard drive & loads it into memory.
* `imshow` take stuff from memory to screen.
* `imwrite(<filename>, <matrix_back>` basic functions.
* Use a while loop that waits for a key (such as `esc`).&#x20;
* I setup a development environment:

{% embed url="https://www.youtube.com/watch?v=H5-B5qKhtYg" %}

## March 2024
[OpenCV Flash Cards](https://quizlet.com/890677132/opencv-f24_cps465-interactive-media-shen-flash-cards/?i=ss8s&x=1qqt)
```txt
What headers are required for utilizing core, highgui, and imgproc modules of OpenCV?	#include <opencv2/core/core.hpp>\n#include <opencv2/highgui/highgui.hpp>\n#include <opencv2/imgproc/imgproc.hpp>
How do you initialize a VideoCapture object with a specific camera index?	VideoCapture cap(cameraIndex);
How to check if the VideoCapture object has been successfully opened?	if (!cap.isOpened())
What function displays an image in a specified window?	imshow(windowName, frame);
What is the main purpose of the waitKey function in an OpenCV application?	char key_value = waitKey(100); // Captures key press and allows UI refresh
How to define a constructor for a class in C++?	WebcamMosaic(int cameraIndex, int blur_degree) : cameraIndex(cameraIndex), blur_degree(10) { ... }
How do you calculate and apply a mosaic (blurred) effect to a region within an image?	Use a nested loop to average the pixel colors within subregions defined by pixSquareWidth, then apply this average color to the entire subregion.
How to capture mouse events (click and drag) to define regions in a window with OpenCV?	setMouseCallback(windowName, onMouseClick, this);
In the context of C++, how is memory for a new object allocated and constructor called?	WebcamMosaic *app = new WebcamMosaic(1, 40);
How to make a window resizable in OpenCV?	namedWindow(windowName, WINDOW_NORMAL);
Process of averaging pixel values to create a mosaic effect?	Iterate over each sub-region (defined by pixSquareWidth), average the pixel colors within this subregion, and fill the subregion with this average color.
What type of loop structure is commonly used to traverse image regions in OpenCV?	For (const Rect &roi : blurROI) { ... }
How to draw rectangles and circles on an OpenCV Mat object?	rectangle(frame, rect, Scalar(0, 0, 255), 2);\ncircle(frame, Point(x, y), radius, Scalar(0, 0, 255), thickness);
How to correctly capture and handle mouse events for selecting regions to blur in an OpenCV application?	Implement static void onMouseClick(int event, int x, int y, int flags, void *userdata) with EVENT_LBUTTONDOWN, EVENT_MOUSEMOVE, and EVENT_LBUTTONUP.
How to exit a loop based on keyboard input in an OpenCV window?	if (processKeyboardInput(key_value)) { break; }

How to define and initialize a Mat object in OpenCV?	Mat image = Mat(800, 1000, CV_8UC3); image = Scalar(255, 255, 255);
How to define a Point in OpenCV?	Point A; // Or initialize directly: Point A(x, y);
How to create and show a window that displays an image?	namedWindow("canvas"); imshow("canvas", image);
How to set a mouse callback function in OpenCV?	setMouseCallback("canvas", onMyMouse2);
How to detect a left mouse button down event?	if(event == EVENT_LBUTTONDOWN)
How to calculate the Euclidean distance between two points?	float dis = sqrt(pow(pt_list[i].x - x, 2.0) + pow(pt_list[i].y - y, 2.0));
How to draw a circle in OpenCV?	circle(image, Point(x, y), 2, Scalar(0, 0, 255), 3);
How to draw a line between two points in OpenCV?	line(image, pt_list[i], pt_list[i+1], Scalar(0, 0, 0), 3);
How to clear an image and fill it with white color?	image = Scalar(255, 255, 255);
How to wait for a key press in OpenCV?	char key_value = waitKey(1);
How to exit a loop with the ESC key in OpenCV?	if(key_value == 27) break;
What is the purpose of using "invert" function in spline drawing?	invert(M, M_inverse); // To calculate the inverse of matrix M for spline calculation.
How to draw a Bezier Spline from control points?	Use a loop to increment t from 0.0 to 1.0, calculate x and y using Bezier formula, then draw points.
How to capture mouse movement for dragging a point?	Check for dragging_mode in EVENT_MOUSEMOVE and update pt_list[pt_idx] with the new position.
When to update the image with newly drawn shapes or lines?	After handling mouse events like adding a point or dragging, clear the image and redraw everything.

What is the primary library needed to work with OpenCV in Python?	cv2
What function is used to read an image in OpenCV?	cv2.imread('path/to/image', flag)
What flag should be used with cv2.imread to load an image in grayscale mode?	cv2.IMREAD_GRAYSCALE or 0
How do you display an image with OpenCV?	cv2.imshow('window name', imageVariable)
What function waits for a specified milliseconds for a keyboard event?	cv2.waitKey(milliseconds)
How do you write an image to a file in OpenCV?	cv2.imwrite('path/to/destination', imageVariable)
What function releases all OpenCV windows and deallocates any associated memory usage?	cv2.destroyAllWindows()
How do you convert an image from BGR to Grayscale?	cv2.cvtColor(imageVariable, cv2.COLOR_BGR2GRAY)
How do you draw a line on an image with OpenCV?	cv2.line(imageVariable, startPoint, endPoint, color, thickness)
How do you draw a rectangle in OpenCV?	cv2.rectangle(imageVariable, topLeftCorner, bottomRightCorner, color, thickness)
How do you capture video from a webcam with OpenCV?	cv2.VideoCapture(0)
After capturing video frames, how do you release the video capture object?	videoCaptureVariable.release()
What is the purpose of the cv2.VideoWriter class?	To write videos or sequence of images to a file
What method is used to detect the contours in a binary image?	cv2.findContours(imageVariable, retrievalMode, approximationMethod)
What function is used to approximate the shape of a contour?	cv2.approxPolyDP(contour, epsilon, closed)
How do you apply Gaussian Blur to an image?	cv2.GaussianBlur(imageVariable, (kernelWidth, kernelHeight), sigmaX)
What function is used to detect edges in an image?	cv2.Canny(imageVariable, threshold1, threshold2)

What library is primarily used for image processing in Python?	cv2
How to create a blank white canvas in OpenCV?	cv2.imshow('Canvas', 255 * np.ones((height, width, 3), np.uint8))
How to draw a circle for each left mouse click in OpenCV?	Use cv2.setMouseCallback('Canvas', functionName) and check for cv2.EVENT_LBUTTONDOWN inside the callback.
How are Bezier Splines defined in terms of points?	Defined by 4 points: 1st and 4th points are fixed, and 2nd and 3rd are controlling points.
What function removes the last selected point with right mouse click?	Use cv2.setMouseCallback and check for cv2.EVENT_RBUTTONDOWN inside the callback, then pop the last point.
How to draw control lines between points for a spline?	Use cv2.line(image, point1, point2, color, thickness) for drawing control lines between 1st and 2nd points, and between 3rd and 4th points.
How to allow users to modify the curve shape by moving points?	Implement a function to detect mouse drag on points and adjust their positions accordingly.
What indicates a spline can be moved (Translation Feature)?	A small square (Editing Region) turns to green when the mouse is over it.
How to change the spline color when it's highlighted?	Detect keyboard inputs ('R', 'G', 'B', 'P', 'Y') and change the spline's color accordingly without needing mouse click.
How to adjust the thickness of a highlighted spline?	Detect keyboard inputs ('I' to increase, 'D' to decrease) and update the spline's thickness.
What key removes all points and lines, leaving only the spline curves?	Hitting the “.” period key.
What key saves the work to a local '.jpg' file?	Hitting the "s" or "S" key.

```