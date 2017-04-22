/*
 * SampleClass.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: ndy
 */

#include "../SampleClassAndMethods/SampleClass.h"

SampleClass::SampleClass() {
	// TODO Auto-generated constructor stub
	this->arg1 = 2;
	this->arg2 = 2.3;
}

void SampleClass::SampleClassMethod() {
	float test = this->SampleClassRecursiveMethod(this->getArg2());
	std::cout<<"Test result "<<test;
}

int SampleClass::SampleClassReturningMethod() {
	int k = 5;
	return k;
}

float SampleClass::SampleClassRecursiveMethod(float a) {
	if (a<1){
		return a;
	}
	return this->SampleClassRecursiveMethod(a-1.0)+a;
}

bool SampleClass::SampleClassParametrizedMethod(int a,int b) {
	return a>b;
}

SampleClass::~SampleClass() {
	delete this->arg1;
	delete this->arg2;
}

void SampleMethod() {
	float test = SampleRecursiveMethod(2.3);
	std::cout<<"Test result "<<test;
}

int SampleReturningMethod() {
	int k = 5;
	return k;
}

float SampleRecursiveMethod(float a) {
	if (a<1){
		return a;
	}
	return SampleRecursiveMethod(a-1.0)+a;
}

bool SampleParametrizedMethod(int a,int b) {
	return a>b;
}
