/*
	Program Counter class. 
*/
#ifndef PC_H
#define PC_H

class PC {

	int val;
	int inst_count; 
public:
	PC();
	~PC();
	void setPC(int);
	void setInstCount(int);
	void inc();
	bool isEnd();
	void End();


	int operator++(int);
	void  operator=(int val);
};
#endif