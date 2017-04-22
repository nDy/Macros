/*
 * SecondClass.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: ndy
 */

#include "SecondClass.h"

SecondClass::SecondClass() {
	this->Sample = new SampleClass();
}

int SecondClass::RandomMethodThatCallsSampleClass() {
	bool test = this->Sample->SampleClassParametrizedMethod(5,6);

	if(test){
		return 0;
	}
	return 1;
}

SecondClass::~SecondClass() {
	delete this->Sample;
}

