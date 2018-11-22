#include "PC.h"

PC::PC() : val(0), inst_count(0){}
PC::~PC(){}
void PC::setPC(int val) {
	if (val > inst_count-1)
		throw("Ivalid Inst mem address");
	else this->val = val;
}
void PC::setInstCount(int val) {
	inst_count = val;
}
void PC::inc() {
	if (val+1 <= inst_count)
		val = val + 1;
}
int PC::operator++(int) {
	int prev = val;
	inc();
	return prev;
}
void PC::operator=(int val) {
	setPC(val);
}
bool PC::isEnd() {
	if (inst_count == 0) return true;
	else return (val == (inst_count));
}
void PC::End() {
	val = inst_count - 1;
}