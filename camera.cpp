#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv) {
	cv::namedWindow("Example2_10", cv::WINDOW_AUTOSIZE);
	cv::VideoCapture cap;
	cv::Mat frame;
	if (argc ==1) {
		cap.open(0); //open first camera
		for (;;) {
			cap >>frame;
			if( frame.empty() ) break; // Ran out of film
			cv::imshow( "Example2_10", frame );
			if( cv::waitKey(33) >= 0 ) break;
		}
	} else {
		cap.open(argv[1]);
	}

	if (!cap.isOpened()) {
		std::cout << "Couldn't open capture." << std::endl;
		return -1;
	}
}
