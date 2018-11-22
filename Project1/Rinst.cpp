#include "Rinst.h"

Rinst::Rinst(int(*op)(int, int), int * rd, int * rs1, int * rs2) : op(op), ThreeArg(rd, rs1, rs2) {}  
Rinst::Rinst(int(*op)(int, int), int * rd, int  val1, int val2)	 : op(op), ThreeArg(rd,val1,val2){} 
Rinst::Rinst(int(*op)(int, int), int * rd, int  val1, int * rs2)	 : op(op), ThreeArg(rd,val1,rs2) {} 
Rinst::Rinst(int(*op)(int, int), int * rd, int * rs1,	int val2 ) : op(op), ThreeArg(rd, rs1,val2){} 

Rinst::~Rinst() {}

void Rinst::exec() {
	*OneArg::rd = op(*TwoArg::rs, *ThreeArg::rs2);
}


