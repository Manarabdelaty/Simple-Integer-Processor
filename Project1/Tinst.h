/*
	Two arguments arithmetic instrucion class for instructions that perform an arithmetic operation on one argument and 
	stores the result in the desitination register. 
*/
#ifndef  TINST_H
#define TINST_H

#include "TwoArg.h"

class Tinst : public TwoArg {
	int(*op)(int);
public:
	Tinst(int(*op)(int), int *, int *);
	Tinst(int(*op)(int), int *, int );
	~Tinst();
	virtual void exec();
};
#endif // ! TINST_H
