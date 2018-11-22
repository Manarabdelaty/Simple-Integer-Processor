#include "ThreeArg.h"

ThreeArg::ThreeArg(int * rd, int * rs1, int * rs2):TwoArg(rd,rs1) , rs2(rs2)  {


};
ThreeArg::ThreeArg(int * rd, int * rs1, int   rs2) : TwoArg(rd, rs1), rs2_imm(rs2) , rs2(&rs2_imm) {

};
ThreeArg::ThreeArg(int * rd, int  rs1, int * rs2)  : TwoArg(rd, rs1), rs2(rs2) {


};
ThreeArg::ThreeArg(int * rd, int rs1, int  rs2) : TwoArg(rd, rs1), rs2_imm(rs2), rs2(&rs2_imm) {


};

ThreeArg::~ThreeArg(){}
