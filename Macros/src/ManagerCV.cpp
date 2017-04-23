/*
 * ManagerCV.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: ndy
 */

#include "ManagerCV.h"

ManagerCV::ManagerCV() {
}

ManagerCV::ManagerCV(cv::Mat mat) {
	this->image = mat;
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

int ManagerCV::getRows() {
	return this->image.rows;
}

int ManagerCV::getCols() {
	return this->image.cols;
}

void ManagerCV::filter(cv::Mat kernel) {
	cv::Mat mat;
	cv::filter2D(this->image, mat, this->image.depth(), kernel);
}

void ManagerCV::linearBlend(cv::Mat mat, float alpha) {
	cv::Mat tmp;
	cv::addWeighted(this->image, alpha, mat, (1 - alpha), 0.0, tmp);
	this->image = tmp;
}

void ManagerCV::linearTransform(double alpha, int beta) {
	cv::Mat tmp;
	this->image.convertTo(tmp, -1, alpha, beta);
	this->image = tmp;
}

cv::Mat ManagerCV::discreteFourierT() {
	cv::Mat image = this->image;
	if (image.channels() > 1)
		image = this->getColorSwap(ManagerCV::BGR2GRAY);

	cv::Mat padded;
	int m = cv::getOptimalDFTSize(this->image.rows);
	int n = cv::getOptimalDFTSize(this->image.cols);
	cv::copyMakeBorder(this->image, padded, 0, m - this->image.rows, 0,
			n - this->image.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));
	cv::Mat planes[] = { Mat_<float>(padded), cv::Mat::zeros(padded.size(),
	CV_32F) };
	cv::Mat complexI;
	cv::merge(planes, 2, complexI);
	dft(complexI, complexI);
	split(complexI, planes);
	magnitude(planes[0], planes[1], planes[0]);
	cv::Mat magI = planes[0];
	magI += cv::Scalar::all(1);
	log(magI, magI);
	magI = magI(cv::Rect(0, 0, magI.cols & -2, magI.rows & -2));
	int cx = magI.cols / 2;
	int cy = magI.rows / 2;
	cv::Mat q0(magI, cv::Rect(0, 0, cx, cy));
	cv::Mat q1(magI, cv::Rect(cx, 0, cx, cy));
	cv::Mat q2(magI, cv::Rect(0, cy, cx, cy));
	cv::Mat q3(magI, cv::Rect(cx, cy, cx, cy));
	cv::Mat tmp;
	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);
	q1.copyTo(tmp);
	q2.copyTo(q1);
	tmp.copyTo(q2);
	normalize(magI, magI, 0, 1, CV_MINMAX);
	return magI;
}

void ManagerCV::blur(int flag) {

}

ManagerCV::~ManagerCV() {
}

