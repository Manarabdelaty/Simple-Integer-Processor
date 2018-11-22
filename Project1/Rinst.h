/*
	R-type instructions that perform a certain arithmetic operation on two arguments and stores the value in the destination register. 
*/
#ifndef RINST_H
#define RINST_H

#include <iostream>
#include "ThreeArg.h"


class Rinst : public ThreeArg {
	
	int (*op)(int, int);         // Points to the arithmetic operation performed by the instruction
public:

	Rinst(int(*op)(int, int), int *,int*,int*);  
	Rinst(int(*op)(int, int), int *, int, int);
	Rinst(int(*op)(int, int), int *, int, int *);
	Rinst(int(*op)(int, int), int *, int*, int);
	~Rinst();
	virtual void exec();
};
#endif // !RINST_H
