/*
	Jump Instruction class. Jumps to the specified instruction memory address.
*/
#ifndef JUMPINST_H
#define JUMPINST_H

#include "OneArg.h"
#include "PC.h"

class JumpInst: public OneArg {
	PC *pc;
public:
	JumpInst(PC *, int);
	~JumpInst() {};
	virtual void exec();
};

#endif 