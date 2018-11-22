/* 
	Halt instruction class. Stops the execution of the SIM by setting the pc to the last instruction index.
*/
#ifndef HALT_H
#define HALT_H

#include "inst.h"
#include "PC.h"

class Halt: public Inst{
	PC * pc;
public:
	Halt(PC *);
	virtual ~Halt();
	virtual void exec();
};
#endif