#include "OneArg.h"

OneArg::OneArg(int * rd) : rd(rd){}
OneArg::OneArg(int  rd) : rd_val(rd), rd(&rd_val) {}

OneArg::~OneArg(){}

bool OneArg::validate(std::string rd) {
	if (!(rd[0] == ADDR)) throw("Destination Register must be an address");
	return true;
}