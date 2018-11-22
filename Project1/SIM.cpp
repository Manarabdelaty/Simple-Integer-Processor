#include "SIM.h"

SIM::SIM()  {}
SIM::~SIM(){}

void SIM::exec(std::string fname) {
	try 
	{
		int inst_count = p.load(fname, InstMem, &dmem, &pc);
		pc.setInstCount(inst_count);
		while (!pc.isEnd())
			InstMem[pc++]->exec();
	}
	catch(const char * msg){
		std::cerr << msg << std::endl;
	}
}
int SIM::readDatamem(int indx) {
	return dmem[indx];
}