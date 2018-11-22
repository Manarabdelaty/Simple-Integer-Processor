#include "TwoArg.h"

TwoArg::TwoArg(int * rd, int * rs) : rs(rs), OneArg(rd) {

}
TwoArg::TwoArg(int * rd, int  rs) : rs_imm(rs), rs(&rs_imm), OneArg(rd) {
}
TwoArg::~TwoArg() {}
