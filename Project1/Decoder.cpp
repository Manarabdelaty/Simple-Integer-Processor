#include "Decoder.h"


Decoder::Decoder(){}
Decoder::~Decoder(){}

int add(int x, int y) { return x + y; }
int mul(int x, int y) { return x * y; }
int le(int x, int y)  { return x <= y;}
int neg(int x) { return -x;}
int ass(int x) { return x; }

bool Decoder::is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}
int Decoder:: toInt(std::string & str) {
	if (isAddr(str) && is_number(str.substr(1)))
		return atoi(str.substr(1).c_str());
	else if (is_number(str)) {
		return(atoi(str.c_str()));
	}
	else throw("Ivalid address argument ");
};
Inst* Decoder::decode_one(std::string tokens[], Mem<int> * Datamem, PC * pc) {
	if (tokens[0] == "HALT") {
		return new Halt(pc);
	}
	else throw("INVALID INSTRUCTION");
}

Inst* Decoder::decode_two(std::string tokens[], Mem<int> * Datamem, PC *pc) {
	int a1 = toInt(tokens[1]);

	if (tokens[0] == "READ") {
		int * x_ref = &Datamem->operator[](a1);
		OneArg::validate(tokens[1]);
		return new Read(x_ref);
	}
	else if (tokens[0] == "WRITE") {
		if (isAddr(tokens[1])) {
			int * x_ref = &Datamem->operator[](a1);
			return new Write(x_ref);
		}
		else return new Write(a1);
	}
	else if (tokens[0] == "JMP") {
		return new JumpInst (pc, a1);
	}
	else throw("INVALID INSTRUCTION");
}

Inst* Decoder::decode_three(std::string tokens[], Mem<int> * Datamem, PC * pc) {
	int rd_int, rs_int;
	int(*op) (int);
	
	rd_int = toInt(tokens[2]);
	rs_int = toInt(tokens[1]);

	int * rd_ref = &Datamem->operator[](rd_int);

	if (tokens[0] == "NEG") {
		OneArg::validate(tokens[2]);
		op = neg;
	}
	else if (tokens[0] == "ASS") {
		OneArg::validate(tokens[2]);
		op = ass;
	}
	else if (tokens[0] == "JMP0") {

		if (isAddr(tokens[1])) {
			int * in1_ref = &Datamem->operator[](rs_int);
			return new Jump0 (pc, rd_int, in1_ref);
		}
		else {
			return new Jump0 (pc,  rd_int, rs_int); ;
		}
	}
	else throw("INVALID INSTRUCTION");

	if (isAddr(tokens[1])) {
		int * rs_ref = &Datamem->operator[](rs_int);
		return new Tinst (op, rd_ref, rs_ref);
	}
	else {
		return new Tinst (op, rd_ref, rs_int);
	}
}
Inst* Decoder::decode_four(std::string tokens[], Mem<int> * Datamem) {
	int rd_int, rs1_int, rs2_int;
	int(*op) (int, int);

	Rinst::validate(tokens[3]);

	if (tokens[0] == "ADD") 
		op = add;
	else if (tokens[0] == "MUL") 
		op = mul;
	else if (tokens[0] == "LE") 
		op = le;
	else throw("INVALID INSTRUCTION");

	rd_int	= toInt(tokens[3]);
	rs1_int = toInt(tokens[1]);
	rs2_int = toInt(tokens[2]);

	int * rd_ref = &Datamem->operator[](rd_int);

	if (isAddr(tokens[1]) && isAddr(tokens[2])) {			// R-type

		int * rs1_ref = &Datamem->operator[](rs1_int);
		int * rs2_ref = &Datamem->operator[](rs2_int);

		return new Rinst (op, rd_ref, rs1_ref, rs2_ref);
	}
	else if ( isAddr(tokens[1]) || isAddr(tokens[2]))
	{
		if (isAddr(tokens[1])) {
			int && imm_val = static_cast<int &&> (rs2_int);
			int * rs_ref = &Datamem->operator[](rs1_int);
			return new Rinst(op, rd_ref, rs_ref, imm_val);
		}
		else {
			int && imm_val = static_cast<int &&>(rs1_int);
			int * rs_ref = &Datamem->operator[](rs2_int);
			return new Rinst(op, rd_ref, static_cast<int &&>(imm_val), rs_ref);
		}
	}
	else return new Rinst (op, rd_ref, rs1_int, rs2_int);
}

Inst* Decoder::decode(std::string tokens[], int num_tokens, Mem<int> * Datamem,PC * pc) {

	
		if (num_tokens == 1)
			return decode_one(tokens, Datamem, pc);

		else if (num_tokens == 2)
			return decode_two(tokens, Datamem, pc);

		else if (num_tokens == 3)
			return decode_three(tokens, Datamem, pc);

		else return decode_four(tokens, Datamem);
		
};

