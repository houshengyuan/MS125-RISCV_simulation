#ifndef  _MA_H
#define _MA_H
#include"EX.hpp"
#include"IF.hpp"
#include"buffer.hpp"
#include"enum.hpp"
#include"memory.hpp"
const int MOD = 255;
class MA           //将对应值存入内存
{
private:
	buffer *in, *out;
public:
	MA(buffer *tmp1, buffer *tmp2) :in(tmp1), out(tmp2) {}
	void memoryaccess()
	{
		out->type = in->type;
		out->rd = in->rd;
		out->result = in->result;
		out->x = in->x;
		if (in->type == 'S')
		{
			if (in->s == SB)
				sb();
			else if (in->s == SH)
				sh();
			else if (in->s == SW)
				sw();
		}
		else if (in->type == 'I')
		{
			if (in->i == LB)
				lb();
			else if (in->i == LH)
				lh();
			else if (in->i == LW)
				lw();
			else if (in->i == LBU)
				lbu();
			else if (in->i == LHU)
				lhu();
		}
		if (!M1g) M1g = 1;
	}
	void sb()
	{
		b.val[in->address] = in->result;
		if (in->address == 0x30004 && in->type == 'S')
		{
			std::cout << std::dec << (a[10] & 0xff);
			End = 1;
		}
	}
	void sh()
	{
		b.val[in->address] = in->result&MOD;
		b.val[in->address + 1] = in->result >> 8;
	}
	void sw()
	{
		b.val[in->address] = in->result&MOD;
		b.val[in->address + 1] = (in->result >> 8)&MOD;
		b.val[in->address + 2] = (in->result >> 16)&MOD;
		b.val[in->address + 3] = in->result >> 24;
	}
	void lb()
	{
		out->result = signedextend(b.val[in->x1 + signedextend(in->imm2, 12)], 8);
	}
	void lh()
	{
		out->result = signedextend((b.val[in->x1 + signedextend(in->imm2, 12) + 1] << 8) + b.val[in->x1 + signedextend(in->imm2, 12)], 16);
	}
	void lw()
	{
		out->result = (b.val[in->x1 + signedextend(in->imm2, 12) + 3] << 24) + (b.val[in->x1 + signedextend(in->imm2, 12) + 2] << 16) + (b.val[in->x1 + signedextend(in->imm2, 12) + 1] << 8) + b.val[in->x1 + signedextend(in->imm2, 12)];
	}
	void lbu()
	{
		out->result = (unsigned int)(b.val[in->x1 + signedextend(in->imm2, 12)]);
	}
	void lhu()
	{
		out->result = (unsigned int)((b.val[in->x1 + signedextend(in->imm2, 12) + 1] << 8) + b.val[in->x1 + signedextend(in->imm2, 12)]);
	}
};

#endif
