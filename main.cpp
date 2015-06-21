#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;

int main(int argc, char** argv) {
//	Mat inputImage = imread("/home/mjunserver02/다운로드/tlSample00/thumb_IMG_2261_1024.jpg");
//	imshow("Input Image", inputImage);
//	waitKey(0);
	//control tower
	namedWindow("Control", WINDOW_AUTOSIZE);
	int iLowH = 0;
	int iHighH = 179;
	int iLowS = 0;
	int iHighS = 255;
	int iLowV = 0;
	int iHighV = 255;
	createTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
	createTrackbar("HighH", "Control", &iHighH, 179);

	createTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
	createTrackbar("HighS", "Control", &iHighS, 255);

	createTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
	createTrackbar("HighV", "Control", &iHighV, 255);
	//end control tower

	//function start
	while(true){
		Mat imgOriginal = imread("/home/mjunserver02/다운로드/tlSample00/thumb_IMG_2261_1024.jpg");
		Mat imgHSV;
		cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV);
		Mat imgThresholded;
		inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded);
		//inRange(imgHSV, cv::Scalar(0, 100, 100), cv::Scalar(10, 255, 255), imgThresholded);
		//erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
		//dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
		//dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
		//erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
		imshow("Thresholded Image", imgThresholded);
		imshow("Original", imgOriginal);
		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
			{cout << "esc key is pressed by user" << endl; break;}
	}
	return 0;
}
