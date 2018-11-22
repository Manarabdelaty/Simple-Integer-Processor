/*
	Write instruction class for printing the value of the specified data memory address.
*/
#ifndef WRITE_H
#define WRITE_H

#include <iostream>
#include "OneArg.h"

class Write : public OneArg {

public:
	Write(int *);
	Write(int);
	virtual ~Write();
	virtual void exec();

};


#endif