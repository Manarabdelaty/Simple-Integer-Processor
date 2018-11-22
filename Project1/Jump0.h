/*
	Conditional Jump instruction class. Jumps to the specified instruction memory address given that the instruction argument value  is zero
*/
#ifndef JUMP0_H
#define JUMP0_H

#include "JumpInst.h"
#include "PC.h"
class Jump0 : public JumpInst {
	int* in1_ref;
	int in_val;
public:
	Jump0(PC*, int , int *);
	Jump0(PC*, int, int);

	~Jump0(){}
	virtual void exec();
};


#endif 
