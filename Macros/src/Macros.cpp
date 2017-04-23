//============================================================================
// Name        : Macros.cpp
// Author      : nDy
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ManagerCV.h"

int main() {
	ManagerCV* m;

	m = new ManagerCV();

	m->loadFromFile("snap.png",ManagerCV::COLOR);
	std::vector<double> colorpix = m->getPixel(10,10);
	std::cout<<"Vector Dimensions: "<<colorpix.size()<<std::endl;
	std::cout<<"Pixel GRB: "<<colorpix[0]<<","<<colorpix[1]<<","<<colorpix[2]<<std::endl;
	m->goColorSwap(ManagerCV::BGR2GRAY);
	std::vector<double> graypix = m->getPixel(10,10);
	std::cout<<"Vector Dimensions: "<<graypix.size()<<std::endl;
	std::cout<<"Pixel GRAYSCALE: "<<graypix[0]<<std::endl;

	return 0;
}
