/*
	Abstract class for instructions with one argument.
*/
#ifndef ONEARG_H
#define ONEARG_H

#include <string>
#include "inst.h"

#define ADDR '$'

class OneArg: public Inst {

protected:
	int * rd;
	int rd_val;
public:
	OneArg(int *);
	OneArg(int);
	virtual ~OneArg();
	virtual void exec()=0;
	static bool validate(std::string rd);
};



#endif 