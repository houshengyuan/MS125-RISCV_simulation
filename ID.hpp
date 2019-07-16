#ifndef _ID_H
#define _ID_H
#include<iostream>
#include"enum.hpp"
#include"buffer.hpp"
#include"memory.hpp"
#include"registor.hpp"
const int mod5 = 31;
///**********
class ID                     //§ã§â§Ø¨g§Ó¨]¨m¨b
{
private:
	buffer *in, *out;
public:
	ID(buffer *tmp1, buffer *tmp2) :in(tmp1), out(tmp2) {}
	void decode()
	{
		out->x = in->x;
		out->opcode = in->x & 127;
		out->func3 = (in->x >> 12) & 7;
		out->func7 = (in->x >> 25);
		out->result = in->result;
		out->address = in->address;
		out->rs1 = (in->x >> 15)&mod5;
		out->rs2 = (in->x >> 20)&mod5;
		out->rd = (in->x >> 7)&mod5;
		p = REG.find(out->rs1);
		if (p != REG.end()) out->x1 = p->second;
		else out->x1 = a[out->rs1];
		p = REG.find(out->rs2);
		if (p != REG.end()) out->x2 = p->second;
		else out->x2 = a[out->rs2];
		out->imm5 = (in->x >> 7)&mod5;
		out->imm7 = (in->x >> 25) & 127;
		out->imm20 = in->x >> 31;
		out->imm111 = (in->x >> 20) & 1;
		out->imm101 = (in->x >> 21) & 1023;
		out->imm1912 = (in->x >> 12) & 255;
		out->imm1 = (in->x >> 12);
		out->imm2 = in->x >> 20;
		out->imm112 = (in->x >> 7) & 1;
		out->imm41 = (in->x >> 8) & 15;
		out->imm105 = (in->x >> 25) & 63;
		out->imm12 = in->x >> 31;
		if (!M1q) M1q = 1;
	}
};
#endif

