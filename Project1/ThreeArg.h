/*
	Abstract class for instructions with three arguments.
*/
#ifndef ThreeARG_H
#define ThreeARG_H

#include "TwoArg.h"


class ThreeArg : public TwoArg {

protected:
	int * rs2;
	int rs2_imm;
public:
	ThreeArg(int *, int *, int *);
	ThreeArg(int *, int *, int );
	ThreeArg(int *, int , int *);
	ThreeArg(int *, int , int );


	virtual ~ThreeArg();
	virtual void exec() =0;
};



#endif 