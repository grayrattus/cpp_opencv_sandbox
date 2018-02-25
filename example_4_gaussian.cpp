#include <opencv2/opencv.hpp>

void example2_5(const cv::Mat &image) {
	cv::namedWindow("Example2_5-in", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example2_5-out", cv::WINDOW_AUTOSIZE);

	cv::imshow("Example2_5-in", image);
	cv::Mat out;

	cv::GaussianBlur(image, out, cv::Size(5,5), 3,3);
	cv::GaussianBlur(out, out, cv::Size(5,5), 3,3);

	cv::imshow("Example2_5-out", out);
	cv::waitKey(0);
}

void example_pyr_down(const cv::Mat &image) {
	cv::Mat img2;
	cv::namedWindow("Example2_6-in", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example2_6-out", cv::WINDOW_AUTOSIZE);

	cv::imshow("Example2_6-in", image);
	cv::pyrDown(image, img2);
	cv::imshow("Example2_6-out", img2);

	cv::waitKey(0);
}


void example_grayscale_edge_detection(const cv::Mat &image) {
	cv::Mat img_gry, img_cny;
	cv::namedWindow("Example Gray", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example Canny", cv::WINDOW_AUTOSIZE);

	cv::cvtColor(image, img_gry, cv::COLOR_BGR2GRAY);
	cv::imshow("Example2_6-in", img_gry);

	cv::Canny(img_gry, img_cny, 10, 100,3,true);
	cv::imshow("Example2_6-out", img_cny);

	cv::waitKey(0);
}
void example_gaussian_edge_detection(const cv::Mat &image) {
	cv::Mat img_gry, img_cny, img_pyr, img_pyr2;
	cv::namedWindow("Example Gray", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example Canny", cv::WINDOW_AUTOSIZE);

	cv::cvtColor(image, img_gry, cv::COLOR_BGR2GRAY);
	cv::imshow("Example2_6-in", img_gry);

	cv::pyrDown(img_gry, img_pyr);
	cv::pyrDown(img_pyr, img_pyr2);
	cv::Canny(img_pyr2, img_cny, 10, 100,3,true);
	cv::imshow("Example2_6-out", img_cny);

	cv::waitKey(0);
}

void color_edges(const cv::Mat &image) {
	cv::Mat img_gry, img_cny, img_pyr, img_pyr2;
	cv::namedWindow("Example Gray", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example Canny", cv::WINDOW_AUTOSIZE);

	cv::cvtColor(image, img_gry, cv::COLOR_BGR2GRAY);
	cv::imshow("Example2_6-in", img_gry);

	cv::pyrDown(img_gry, img_pyr);
	cv::pyrDown(img_pyr, img_pyr2);
	cv::Canny(img_pyr2, img_cny, 10, 100,3,true);
	cv::imshow("Example2_6-out", img_cny);

	const int x = 16, y = 32;

	cv::Vec3b intensity = image.at<cv::Vec3b>(y,x);

	uchar blue = intensity[0];
	uchar green = intensity[1];
	uchar red = intensity[2];

	std::cout << "At (x,y) = (" << x << "," << y << "): (blue,green,red) = (" <<
		(unsigned int)blue << "," << (unsigned int)green << "," << (unsigned int)red << ")" << std::endl;
	std::cout << "Gray pixel there is: " << 
		(unsigned int)img_gry.at<uchar>(y,x) << std:: endl;
	img_cny.at<uchar>(x,y) = 128;
	cv::waitKey(0);
}

int main() {
	cv::Mat image = cv::imread("/home/grayrattus/me.jpg");
	//example2_5(image);
	//example_pyr_down(image);
	//example_grayscale_edge_detection(image);
	//example_gaussian_edge_detection(image);
	color_edges(image);
	return 0;
}
