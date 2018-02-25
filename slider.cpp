//-L/usr/local/lib -lopencv_videostab -lopencv_ml -lopencv_shape -lopencv_dnn -lopencv_superres -lopencv_photo -lopencv_video -lopencv_stitching -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_objdetect -lopencv_imgproc -lopencv_flann -lopencv_core

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int g_slider_position = 0;
int g_run = 1, g_dontset = 0; //start out in single step mode

cv::VideoCapture g_cap;

void onTrackbarSlide(int pos, void *) {
	g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
	if (!g_dontset) {
		g_run =1;
		g_dontset =0;
	}
}

int main( int argc, char** argv ) {
	cv::namedWindow("Example2_4", cv::WINDOW_AUTOSIZE);
	g_cap.open(string(argv[1]));

	int frames = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT);
	int tmpw = (int)g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
	int tmph = (int)g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);

	cout << "Video has" << frames << " frames of dimensions(" << tmpw << "x" << tmph << endl;
	cv::createTrackbar("Position", "Example2_4", &g_slider_position, frames, onTrackbarSlide);

	cv::Mat frame;
	for (;;) {
		if(g_run != 0) {
			g_cap >> frame;
			if(frame.empty()) break;
			int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);
			g_dontset = 1;
			cv::setTrackbarPos("Position", "Example2_4", current_pos);
			cv::imshow("Example2_4", frame);
			g_run-=1;
		}
		char c = (char)cv::waitKey(10);
		switch(c) {
			case 's':
				g_run =1;
				cout << "Single step, run = " << g_run << endl;
				break;
			case 'r':
				g_run = -1;
				cout << "Run mode, run = " << g_run << endl;
				break;
			case 27:
				break;
		}
	}
	return(0);
}
