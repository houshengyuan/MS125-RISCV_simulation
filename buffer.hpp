#ifndef _BUFFER_H
#define _BUFFER_H
#include"enum.hpp"
class buffer
{
public:
	int x;
	int address;
	int result;
	char type;
	int opcode;
	int func3;
	int func7;
	int out;
	int rs1;
	int rs2;
	int x1;
	int x2;
	int rd;
	int imm1;
	int imm2;
	int imm7;
	int imm5;
	int imm111;
	int imm112;
	int imm41;
	int imm105;
	int imm12;
	int imm20;
	int imm101;
	int imm1912;
	Roperation r;
	Ioperation i;
	Joperation j;
	Boperation b;
	Uoperation u;
	Soperation s;
	buffer()
	{
		x = 0;
		address = 0;
		result = 0;
		type = 0;
		opcode = 0;
		func3 = 0;
		func7 = 0;
		out = 0;
		rs1 = 0;
		rs2 = 0;
		x1 = 0;
		x2 = 0;
		rd = 0;
		imm1 = 0;
		imm2 = 0;
		imm7 = 0;
		imm5 = 0;
		imm111 = 0;
		imm112 = 0;
		imm41 = 0;
		imm105 = 0;
		imm12 = 0;
		imm20 = 0;
		imm101 = 0;
		imm1912 = 0;
	}
};
#endif // _BUFFER_H
