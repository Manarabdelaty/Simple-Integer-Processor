/*
	Parser class. Parses instruction from a .txt file and loads the decoded instructions
	to the instructions memory 
*/
#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include "Mem.h"
#include "inst.h"
#include "Decoder.h"
#include "PC.h"

# define SEP ','
# define TSIZE 4 

class Parser {

	void openFile(std::ifstream &,std::string &);
	int tokenize(const std::string &,std::string []);	
	Decoder d;
	
public:
	Parser();
	~Parser();

	int load(std::string,Mem<Inst*>&, Mem<int> * datamem, PC *);

};
#endif