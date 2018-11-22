#include "Tinst.h"

Tinst::Tinst(int(*op)(int), int * rd, int * rs) : op(op), TwoArg(rd, rs) {}
Tinst::Tinst(int(*op)(int), int * rd, int  rs): op(op), TwoArg(rd ,rs) {}

Tinst::~Tinst(){}

void Tinst::exec() {
	*OneArg::rd = op(*rs);
}