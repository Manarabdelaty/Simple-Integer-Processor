/*
	Instruction Base class. Astract class
*/
#ifndef INST_H
#define INST_H

class Inst {

public:
	Inst() {};
	virtual ~Inst() {};

	virtual void exec()=0;
};
#endif // !INST_H
