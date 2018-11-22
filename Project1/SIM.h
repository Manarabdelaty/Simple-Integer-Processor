/* 
	
*/
#ifndef SIM_H
#define SIM_H

#include <string>
#include "parser.h"
#include "Mem.h"
#include "inst.h"
#include "PC.h"

class SIM {

	Parser p;
	Mem<int> dmem; 
	Mem<Inst*> InstMem;
	PC pc;

public:
	SIM();
	~SIM();
	void exec(std::string fname);
	int readDatamem(int);
};



#endif