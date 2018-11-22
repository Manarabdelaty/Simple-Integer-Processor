/*
	Template class for memory banks (Data memory and instruction memory ).
*/
#ifndef MEM_H
#define MEM_H

#include<iostream>
#define SIZE 1024

template <typename T>
class Mem {
	
	template<typename T> friend std::ostream & operator<< (std::ostream & o,const Mem<T> & );

	T * mem_arr;

	void checkAddr(int addr) {
		if (addr < 0 || addr >= SIZE) throw ("Invalid Memory address");
	};
public:

	Mem();
	virtual ~Mem();

	T read(int);
	void write(int, T);
	T & operator[](int);
};
#include "Mem.cpp"
#endif