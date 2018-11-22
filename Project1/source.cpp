#include <iostream>
#include <string>
using namespace std;

#include "SIM.h"

string file_name = "add.txt";

int main() {

	SIM sim;
	sim.exec(file_name);

	cout << "Data Mem " << endl;
	cout << "---------" << endl;
	for (int i = 0; i < 10; i++)
		cout << "loc " << i << " val " << sim.readDatamem(i) << endl;

	system("pause");
	return 0;
}