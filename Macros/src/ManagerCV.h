/*
 * ManagerCV.h
 *
 *  Created on: Apr 22, 2017
 *      Author: ndy
 */

#ifndef MANAGERCV_H_
#define MANAGERCV_H_

#include <opencv2/imgproc/imgproc.hpp>
#include <string>

class ManagerCV {
private:
	Mat image;
	int loadflag;

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

	enum WWINDOWFLAGS{
		NORMAL = WINDOW_NORMAL,
		AUTOSIZE = WINDOW_AUTOSIZE
	};

	ManagerCV();

	void loadFromFile(std::string,int);

	void saveToFile(std::string);

	Mat getColorSwap(int);

	void goColorSwap(int);

	void showImage(std::string,int);

	void getPixel(int,int);

	virtual ~ManagerCV();
};

#endif /* MANAGERCV_H_ */
