#include "Halt.h"

Halt::Halt(PC * pc): pc(pc){}
Halt::~Halt() {}

void Halt::exec(){
	pc->End();
}