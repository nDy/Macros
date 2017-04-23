/*
 * ManagerCV.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: ndy
 */

#include "ManagerCV.h"

ManagerCV::ManagerCV() {
	this->loadflag = 0;
}

void ManagerCV::loadFromFile(std::string path, int flag) {
	this->image = cv::imread(path, flag);
	this->loadflag = flag;
}

void ManagerCV::saveToFile(std::string path) {
	cv::imwrite(path, this->image);
}

cv::Mat ManagerCV::getColorSwap(int flag) {
	cv::Mat img;
	cv::cvtColor(this->image, img, flag);
	return img;
}

void ManagerCV::showImage(std::string WindowName, int flag) {
	cv::namedWindow(WindowName, flag);
	cv::imshow(WindowName, this->image);
}

void ManagerCV::goColorSwap(int colorFlag) {
	cv::Mat aux;
	cv::cvtColor(this->image, aux, colorFlag);
	this->image = aux;
}

void ManagerCV::getPixel(int int1, int int2) {
	//Maybe
	/*
	for(int i=0; i<A.rows; i++){
	   for(int j=0; j<A.cols; j++){
		   	   if(this->loadflag==LOADFLAGS::COLOR){
		   		   G = this->image.data[this->image.step[0]*i + this->image.step[1]* j + 0];
		   		   B = this->image.data[this->image.step[0]*i + this->image.step[1]* j + 1];
		   		   R = this->image.data[this->image.step[0]*i + this->image.step[1]* j + 2];
		   	   }
	    }
	}
	*/
}

ManagerCV::~ManagerCV() {
}

