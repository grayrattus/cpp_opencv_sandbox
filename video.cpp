//-L/usr/local/lib -lopencv_videostab -lopencv_ml -lopencv_shape -lopencv_dnn -lopencv_superres -lopencv_photo -lopencv_video -lopencv_stitching -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_objdetect -lopencv_imgproc -lopencv_flann -lopencv_core

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <string>

using namespace std;

int main( int argc, char** argv ) {

	cv::namedWindow( "Example3", cv::WINDOW_AUTOSIZE );
	cv::VideoCapture cap;
	cap.open( string(argv[1]) );

	cv::Mat frame;
	for(;;) {
		cap >>frame;
		if( frame.empty() ) break; // Ran out of film
		cv::imshow( "Example3", frame );
		if( cv::waitKey(33) >= 0 ) break;
	}

	return 0;
}
