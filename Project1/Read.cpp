#include "Read.h"
Read::Read(int * x): OneArg(x){}
Read::~Read(){}

void Read::exec() {
	int a;
	std::cin >> a;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "You must enter an integer number" << std::endl;
		std::cin >> a;
	}
	*OneArg::rd = a;
}
