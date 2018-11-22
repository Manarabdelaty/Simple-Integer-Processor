#include "JumpInst.h"

JumpInst::JumpInst(PC * pc, int addr): pc(pc), OneArg(addr){}

void JumpInst::exec() {
	*pc = *OneArg::rd;
}
