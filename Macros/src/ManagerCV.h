/*
 * ManagerCV.h
 *
 *  Created on: Apr 22, 2017
 *      Author: ndy
 */

#ifndef MANAGERCV_H_
#define MANAGERCV_H_

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <string>

class ManagerCV {
private:
	cv::Mat image;

public:

	enum LOADFLAGS {
		DEPTH = CV_LOAD_IMAGE_ANYDEPTH,
		COLOR = CV_LOAD_IMAGE_COLOR,
		GRAYSCALE = CV_LOAD_IMAGE_GRAYSCALE,
		ALPHA = -1
	};

	enum COLORFLAGS{
		BGR2GRAY = CV_RGB2GRAY,
		BGR2HSV = CV_BGR2HSV,
		BGR2HLS = CV_BGR2HLS,
		HSV2BGR = CV_HSV2BGR,
		HLS2BGR = CV_HLS2BGR
	};

	enum WINDOWFLAGS{
		NORMALSIZE = CV_WINDOW_NORMAL,
		AUTOSIZE = CV_WINDOW_AUTOSIZE
	};

	enum BLURLAGS{
			NORMAL,GAUSSIAN,MEDIAN,BILATERAL
		};

	ManagerCV();

	ManagerCV(cv::Mat);

	const cv::Mat& getImage() const {
		return image;
	}

	void setImage(const cv::Mat& image) {
		this->image = image;
	}

	void loadFromFile(std::string,int);

	void saveToFile(std::string);

	cv::Mat getColorSwap(int);

	void goColorSwap(int);

	void showImage(std::string,int);

	std::vector<double> getPixel(int,int);

	void setPixel(int,int,std::vector<double>);

	int getRows();

	int getCols();

	void filter(cv::Mat);

	void linearBlend(cv::Mat,float);

	void linearTransform(double,int);

	cv::Mat discreteFourierT();

	void blur(int);

	virtual ~ManagerCV();

};

#endif /* MANAGERCV_H_ */
