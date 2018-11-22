#include "Jump0.h"

Jump0::Jump0( PC * pc, int addr, int * in) : in1_ref(in), JumpInst(pc, addr){}
Jump0::Jump0( PC * pc, int addr, int  val): in_val(val), in1_ref(&in_val), JumpInst(pc, addr){}

void Jump0::exec() {
	if (*in1_ref == 0)
		JumpInst::exec();
}