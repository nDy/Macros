/*
 * main.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: ndy
 */


#include "../SampleClassAndMethods/SampleClass.h"

int main(int argc, char **argv) {
	SampleClass* instance;
	instance = new SampleClass();

	instance->SampleClassMethod();

	int test = instance->SampleClassReturningMethod();

	float testf = instance->SampleClassRecursiveMethod(3.2);

	bool testb = instance->SampleClassParametrizedMethod(5,6);

}


