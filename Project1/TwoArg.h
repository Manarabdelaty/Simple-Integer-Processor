/*
	Abstract class for instructions with two arguments.
*/
#ifndef TWOARG_H
#define TWOARG_H

#include "OneArg.h"


class TwoArg : public OneArg {

protected:
	int * rs;
	int rs_imm;
public:
	TwoArg(int *, int *);
	TwoArg(int *, int );
	virtual ~TwoArg();
	virtual void exec() = 0;
};



#endif 