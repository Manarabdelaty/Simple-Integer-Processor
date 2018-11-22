/*
	Read Instruction class. Reads an integer from the keyboard and stores it in the specified data memory address.
*/
#ifndef READ_H
#define READ_H

#include <iostream>
#include<limits>
#include "OneArg.h"

class Read : public OneArg {

public:
	Read(int *);
	virtual ~Read();
	virtual void exec();
};
#endif // !READ_H
