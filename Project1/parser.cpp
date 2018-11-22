#include "parser.h"

Parser::Parser() {}
Parser::~Parser() {}

int Parser::load(std::string fname , Mem<Inst *> & inst_mem , Mem<int> * data_mem, PC * pc) {
	std::ifstream input_file;
	std::string inst_line;
	int num_tokens;
	int indx = 0;
	
	openFile(input_file, fname);

	while (getline(input_file, inst_line)) {
		if (!inst_line.empty()) {
			std::string tokens[TSIZE];
			num_tokens = tokenize(inst_line, tokens);
			inst_mem[indx++] = d.decode(tokens, num_tokens, data_mem, pc);
			}
	}
	input_file.close();
	return indx;
}
void Parser::openFile(std::ifstream & input_file , std::string & fname) {
	input_file.open(fname);
	if (!input_file.is_open())
		throw("Invalid File Name");
}
int Parser::tokenize(const std::string & inst_line, std::string res[]) {
	std::string token;
	std::string line;
	std::regex e(" ");
	int indx = 0;

	std::regex_replace(std::back_inserter(line), inst_line.begin(), inst_line.end(), e, ",");
	std::istringstream tokenStream(line);

	while (std::getline(tokenStream, token, SEP))
		if (indx >= TSIZE) 
			throw("Number of Instruction arguments can't be greater than 3 " );
		else if (!token.empty())
			res[indx++] = token;
	return indx;
}

