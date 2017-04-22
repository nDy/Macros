/*
 * SampleClass.h
 *
 *  Created on: Apr 22, 2017
 *      Author: ndy
 */

#ifndef SAMPLECLASS_H_
#define SAMPLECLASS_H_

void SampleMethod();
int SampleReturningMethod();
float SampleRecursiveMethod(float);
bool SampleParametrizedMethod(int, int);

class SampleClass {
private:
	int arg1;
	float arg2;
public:
	SampleClass();
	void SampleClassMethod();
	int SampleClassReturningMethod();
	float SampleClassRecursiveMethod(float);
	bool SampleClassParametrizedMethod(int, int);
	virtual ~SampleClass();

	int getArg1() const {
		return arg1;
	}

	void setArg1(int arg1) {
		this->arg1 = arg1;
	}

	float getArg2() const {
		return arg2;
	}

	void setArg2(float arg2) {
		this->arg2 = arg2;
	}
};

#endif /* SAMPLECLASS_H_ */
