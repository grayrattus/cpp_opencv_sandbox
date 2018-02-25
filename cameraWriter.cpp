#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv) {
	cv::namedWindow("Example2_10", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Log_Polar", cv::WINDOW_AUTOSIZE);

	cv::VideoCapture cap;
	cap.open(0); //open first camera

	double fps = cap.get(cv::CAP_PROP_FPS);
	cv::Size size((int)cap.get(cv::CAP_PROP_FRAME_WIDTH),
			(int)cap.get(cv::CAP_PROP_FRAME_HEIGHT));

	cv::VideoWriter writer;
	writer.open("omfg.mjpg", CV_FOURCC('M','J','P', 'G'), fps, size);

	cv::Mat logpolar_frame, bgr_frame;

	for (;;) {
		cap >> bgr_frame;
		if( bgr_frame.empty() ) break; // Ran out of film
		cv::imshow( "Log_Polar", bgr_frame);
		cv::logPolar(
				bgr_frame, // input color frame
				logpolar_frame, // output log-polar frame
				cv::Point2f( // punkty centralne log-polar transoformation
					bgr_frame.cols/2, //x
					bgr_frame.rows/2 //y
					),
				40, // Magnituge(scale, parameter)
				cv::WARP_FILL_OUTLIERS // Fill outliers with 'zero'
			    );
		cv::imshow("Log_Polar", logpolar_frame);
		writer << logpolar_frame;
		char c = cv::waitKey(10);
		if (c == 27) break;
	}
	cap.release();
}
