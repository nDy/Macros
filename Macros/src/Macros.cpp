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

	m->loadFromFile("snap.png", ManagerCV::COLOR);

	m->showImage("color",ManagerCV::NORMALSIZE);

	ManagerCV* g;
	g = new ManagerCV();

	g->loadFromFile("snap2.png", ManagerCV::COLOR);

	g->showImage("grayscale",ManagerCV::NORMALSIZE);

	m->linearBlend(g->getImage(),0.5);

	m->showImage("blend",ManagerCV::NORMALSIZE);

	cv::waitKey(0);

	return 0;
}
