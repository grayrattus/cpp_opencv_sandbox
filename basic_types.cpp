//-L/usr/local/lib -lopencv_videostab -lopencv_ml -lopencv_shape -lopencv_dnn -lopencv_superres -lopencv_photo -lopencv_video -lopencv_stitching -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_objdetect -lopencv_imgproc -lopencv_flann -lopencv_core

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <string>
#include <iostream>

using namespace std;

int main( int argc, char** argv ) {

	cout << cv::getCPUTickCount() << endl;
	cv::Point2f p1{10,10};
	cv::Point2f p2{20,20};

	cout << "p1.x" << p1.x  << " p1.y" << p1.y << endl;
	cout << "p2.x" << p2.x  << " p2.y" << p2.y << endl;

	cv::Point2f sum = p1 + p2;
	cv::Point2f diff = p1 - p2;
	cout << "sum.x" << sum.x  << " sum.y" << sum.y << endl;
	cout << "diff.x" << diff.x  << " diff.y" << diff.y << endl;

	cv::Rect rect1{p1,p2};

	cv::Point2f p3{100,100};
	cout << "rect1.area()" << rect1.area() << endl;
	cout << "p1.inside(rect1): " << p1.inside(rect1) << endl;
	cout << "p3.inside(rect1): " << p3.inside(rect1) << endl;

	cv::Matx33f mat33f{10,10,10,10,10,10,10,10,10};
	cv::Matx33f mat33f_2{10,10,10,10,10,10,10,10,10};
	cout << mat33f.row(2) << endl;
	cout << mat33f.col(2) << endl;
	cout << mat33f(2,2) << endl;

	cv::Matx33f sum_mat = mat33f+mat33f_2;
	cout << sum_mat << endl;



	cout << cv::getCPUTickCount();

}
