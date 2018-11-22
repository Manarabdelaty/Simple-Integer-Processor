#include "Write.h"

Write::Write(int * x):OneArg(x){}
Write::Write(int  x): OneArg(x) {}
Write::~Write() {}
void Write::exec() {
	std::cout << *OneArg::rd << std::endl;
}