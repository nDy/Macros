/*
 * ManagerCV.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: ndy
 */

#include "ManagerCV.h"

ManagerCV::ManagerCV() {
}

void ManagerCV::loadFromFile(std::string path, int flag) {
	this->image = cv::imread(path, flag);
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

std::vector<double> ManagerCV::getPixel(int Row, int Col) {
	std::vector<double> out;
	cv::Mat aux;
	this->image(cv::Rect(Col, Row, 1, 1)).convertTo(aux, CV_64F);
	switch (aux.channels()) {
	case 1: {
		cv::Scalar tmpsc = aux.at<double>(0);
		out.push_back(tmpsc[0]);
		break;
	}
	case 2: {
		cv::Scalar tmpsc = aux.at<cv::Vec2d>(0);
		out.push_back(tmpsc[0]);
		out.push_back(tmpsc[1]);
		break;
	}
	case 3: {
		cv::Scalar tmpsc = aux.at<cv::Vec3d>(0);
		out.push_back(tmpsc[0]);
		out.push_back(tmpsc[1]);
		out.push_back(tmpsc[2]);
		break;
	}
	case 4: {
		cv::Scalar tmpsc = aux.at<cv::Vec4d>(0);
		out.push_back(tmpsc[0]);
		out.push_back(tmpsc[1]);
		out.push_back(tmpsc[2]);
		out.push_back(tmpsc[3]);
		break;
	}
	}

	return out;
}

void ManagerCV::setPixel(int row, int col, std::vector<double> vec) {

	switch (this->image.channels()) {

	case 1: {
		if (this->image.depth() == CV_8U)
			this->image.at<uchar>(row, col, 0) = vec[0];
		else
			this->image.at<schar>(row, col, 0) = vec[0];
		break;
	}
	case 2: {
		for (int var = 0; var < this->image.channels(); ++var) {
			if (this->image.depth() == CV_32F or this->image.depth() == CV_64F)
				this->image.at<cv::Vec2f>(row, col, var) = vec[var];
			else
				this->image.at<cv::Vec2b>(row, col, var) = vec[var];
		}
		break;
	}
	case 3: {
		for (int var = 0; var < this->image.channels(); ++var) {
			if (this->image.depth() == CV_32F or this->image.depth() == CV_64F)
				this->image.at<cv::Vec3f>(row, col, var) = vec[var];
			else
				this->image.at<cv::Vec3b>(row, col, var) = vec[var];
		}
		break;
	}
	case 4: {
		for (int var = 0; var < this->image.channels(); ++var) {
			if (this->image.depth() == CV_32F or this->image.depth() == CV_64F)
				this->image.at<cv::Vec4f>(row, col, var) = vec[var];
			else
				this->image.at<cv::Vec4b>(row, col, var) = vec[var];
		}
		break;
	}

	}
}

ManagerCV::~ManagerCV() {
}

