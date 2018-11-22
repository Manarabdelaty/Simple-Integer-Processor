/*
	Decoder class. Takes the tokenized instruction and instantiates an object corresponding to that particular instruction.
*/
#ifndef DECODER_H
#define DECODER_H

#include <string>
#include "PC.h"
#include "inst.h"
#include "Rinst.h"
#include "Tinst.h"
#include "Halt.h"
#include "Mem.h"
#include "JumpInst.h"
#include "Jump0.h"
#include "Read.h"
#include "Write.h"

# define DOLLAR '$'

class Decoder {
	bool is_number(const std::string& s);
	bool isAddr(std::string & str) { 
		return (str[0] == DOLLAR);
	
	}
	int toInt(std::string & str);
	Inst* decode_one(std::string tokens[],  Mem<int> *, PC * pc);
	Inst* decode_two(std::string tokens[], Mem<int> *, PC * pc);
	Inst* decode_three(std::string tokens[], Mem<int> *, PC *);
	Inst* decode_four(std::string tokens[], Mem<int> *);
public:
	Decoder();
	~Decoder();
	Inst * decode(std::string tokens[], int num_tokens , Mem<int> *, PC *);
};
#endif