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
	m->goColorSwap(ManagerCV::BGR2GRAY);
	m->showImage("Squanch",ManagerCV::NORMALSIZE);

	cv::waitKey(0);

	return 0;
}
