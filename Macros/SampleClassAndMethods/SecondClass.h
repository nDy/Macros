/*
 * SecondClass.h
 *
 *  Created on: Apr 22, 2017
 *      Author: ndy
 */

#ifndef SECONDCLASS_H_
#define SECONDCLASS_H_

#include "SampleClass.h"

class SecondClass {
public:
	SampleClass* Sample;
	SecondClass();
	int RandomMethodThatCallsSampleClass();
	virtual ~SecondClass();
};

#endif /* SECONDCLASS_H_ */
