#ifndef _EX_H
#define _EX_H
#include<iostream>
#include"enum.hpp"
#include"buffer.hpp"
#include"ID.hpp"
class Rtype
{
private:
	buffer *x, *y;
	unsigned int t1;
	unsigned int t2;
public:
	Rtype(buffer *tmp1, buffer *tmp2) :x(tmp1), y(tmp2)
	{
		t1 = x->x1;
		t2 = x->x2;
	}
	void excution()
	{
		if (y->r == ADD)
			add();
		else if (y->r == SLT)
			slt();
		else if (y->r == SLTU)
			sltu();
		else if (y->r == AND)
			and1();
		else if (y->r == OR)
			or1();
		else if (y->r == XOR)
			xor1();
		else if (y->r == SLL)
			sll();
		else if (y->r == SRL)
			srl();
		else if (y->r == SUB)
			sub();
		else if (y->r == SRA)
			sra();
		y->rd = x->rd;
	}
	void add()
	{
		y->result = x->x1 + x->x2;
		p = REG.find(x->rd);
		if (p != REG.end()) REG.erase(x->rd);
		if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
		else REG.insert(std::pair<int, int>(0, 0));
	}
	void slt()
	{
		if (x->x1 < x->x2)
			y->result = 1;
		else
			y->result = 0;
		p = REG.find(x->rd);
		if (p != REG.end()) REG.erase(x->rd);
		if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
		else REG.insert(std::pair<int, int>(0, 0));
	}
	void sltu()
	{
		if (t1 != 0)
		{
			if (t1 < t2)
				y->result = 1;
			else
				y->result = 0;
			p = REG.find(x->rd);
			if (p != REG.end()) REG.erase(x->rd);
			if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
			else REG.insert(std::pair<int, int>(0, 0));
		}
		else
		{
			if (t2 != 0)
				y->result = 1;
			else
				y->result = 0;
			p = REG.find(x->rd);
			if (p != REG.end()) REG.erase(x->rd);
			if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
			else REG.insert(std::pair<int, int>(0, 0));
		}
	}
	void and1()
	{
		y->result = x->x1&x->x2;
		p = REG.find(x->rd);
		if (p != REG.end()) REG.erase(x->rd);
		if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
		else REG.insert(std::pair<int, int>(0, 0));
	}
	void or1()
	{
		y->result = x->x1 | x->x2;
		p = REG.find(x->rd);
		if (p != REG.end()) REG.erase(x->rd);
		if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
		else REG.insert(std::pair<int, int>(0, 0));
	}
	void xor1()
	{
		y->result = x->x1^x->x2;
		p = REG.find(x->rd);
		if (p != REG.end()) REG.erase(x->rd);
		if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
		else REG.insert(std::pair<int, int>(0, 0));
	}
	void sll()
	{
		y->result = x->x1 << x->x2;
		p = REG.find(x->rd);
		if (p != REG.end()) REG.erase(x->rd);
		if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
		else REG.insert(std::pair<int, int>(0, 0));
	}
	void srl()
	{
		y->result = t1 >> t2;
		p = REG.find(x->rd);
		if (p != REG.end()) REG.erase(x->rd);
		if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
		else REG.insert(std::pair<int, int>(0, 0));
	}
	void sub()
	{
		y->result = x->x1 - x->x2;
		p = REG.find(x->rd);
		if (p != REG.end()) REG.erase(x->rd);
		if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
		else REG.insert(std::pair<int, int>(0, 0));
	}
	void sra()
	{
		y->result = x->x1 >> x->x2;
		p = REG.find(x->rd);
		if (p != REG.end()) REG.erase(x->rd);
		if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
		else REG.insert(std::pair<int, int>(0, 0));
	}
};

class Itype
{
private:
	buffer *x, *y;
	unsigned int t1;
	unsigned int t2;
public:
	Itype(buffer *tmp1, buffer *tmp2) :x(tmp1), y(tmp2)
	{
		t1 = x->x1;
		t2 = x->rs2;
	}
	void excution()
	{
		if (y->i == ADDI)
			addi();
		else if (y->i == SLTI)
			slti();
		else if (y->i == SLTIU)
			sltiu();
		else if (y->i == ANDI)
			andi();
		else if (y->i == ORI)
			ori();
		else if (y->i == XORI)
			xori();
		else if (y->i == SLLI)
			slli();
		else if (y->i == SRLI)
			srli();
		else if (y->i == SRAI)
			srai();
		else if (y->i == JALR)
			jalr();
		else if (y->i == LB)
		{
			p = REG.find(x->rd);
			if (p != REG.end()) REG.erase(x->rd);
			if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, signedextend(b.val[x->x1 + signedextend(x->imm2, 12)], 8)));
			else REG.insert(std::pair<int, int>(0, 0));
		}
		else if (y->i == LH)
		{
			p = REG.find(x->rd);
			if (p != REG.end()) REG.erase(x->rd);
			if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, signedextend((b.val[x->x1 + signedextend(x->imm2, 12) + 1] << 8) + b.val[x->x1 + signedextend(x->imm2, 12)], 16)));
			else REG.insert(std::pair<int, int>(0, 0));
		}
		else if (y->i == LW)
		{
			p = REG.find(x->rd);
			if (p != REG.end()) REG.erase(x->rd);
			if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, (b.val[x->x1 + signedextend(x->imm2, 12) + 3] << 24) + (b.val[x->x1 + signedextend(x->imm2, 12) + 2] << 16) + (b.val[x->x1 + signedextend(x->imm2, 12) + 1] << 8) + b.val[x->x1 + signedextend(x->imm2, 12)]));
			else REG.insert(std::pair<int, int>(0, 0));
		}
		else if (y->i == LBU)
		{
			p = REG.find(x->rd);
			if (p != REG.end()) REG.erase(x->rd);
			if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, (unsigned int)(b.val[x->x1 + signedextend(x->imm2, 12)])));
			else REG.insert(std::pair<int, int>(0, 0));
		}
		else if (y->i == LHU)
		{
			p = REG.find(x->rd);
			if (p != REG.end()) REG.erase(x->rd);
			if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, (unsigned int)((b.val[x->x1 + signedextend(x->imm2, 12) + 1] << 8) + b.val[x->x1 + signedextend(x->imm2, 12)])));
			else REG.insert(std::pair<int, int>(0, 0));
		}
		y->rd = x->rd;
		y->x1 = x->x1;
		y->imm2 = x->imm2;

	}
	void addi()
	{
		y->result = x->x1 + x->imm2;
		p = REG.find(x->rd);
		if (p != REG.end()) REG.erase(x->rd);
		if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
		else REG.insert(std::pair<int, int>(0, 0));
	}
	void slti()
	{
		if (x->rs1 < x->imm2)
			y->result = 1;
		else
			y->result = 0;
		p = REG.find(x->rd);
		if (p != REG.end()) REG.erase(x->rd);
		if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
		else REG.insert(std::pair<int, int>(0, 0));
	}
	void sltiu()
	{
		if (t2 != 1)
		{
			if (t1 < t2)
				y->result = 1;
			else
				y->result = 0;
			p = REG.find(x->rd);
			if (p != REG.end()) REG.erase(x->rd);
			if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
			else REG.insert(std::pair<int, int>(0, 0));
		}
		else
		{
			if (t1 == 0)
				y->result = 1;
			else
				y->result = 0;
			p = REG.find(x->rd);
			if (p != REG.end()) REG.erase(x->rd);
			if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
			else REG.insert(std::pair<int, int>(0, 0));
		}
	}
	void andi()
	{
		y->result = x->x1&x->imm2;
		p = REG.find(x->rd);
		if (p != REG.end()) REG.erase(x->rd);
		if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
		else REG.insert(std::pair<int, int>(0, 0));
	}
	void ori()
	{
		y->result = x->x1 | x->imm2;
		p = REG.find(x->rd);
		if (p != REG.end()) REG.erase(x->rd);
		if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
		else REG.insert(std::pair<int, int>(0, 0));
	}
	void xori()
	{
		y->result = x->x1^x->imm2;
		p = REG.find(x->rd);
		if (p != REG.end()) REG.erase(x->rd);
		if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
		else REG.insert(std::pair<int, int>(0, 0));
	}
	void slli()
	{
		y->result = x->x1 << x->rs2;
		p = REG.find(x->rd);
		if (p != REG.end()) REG.erase(x->rd);
		if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
		else REG.insert(std::pair<int, int>(0, 0));
	}
	void srli()
	{
		y->result = t1 >> t2;
		p = REG.find(x->rd);
		if (p != REG.end()) REG.erase(x->rd);
		if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
		else REG.insert(std::pair<int, int>(0, 0));
	}
	void srai()
	{
		y->result = x->x1 >> x->rs2;
		p = REG.find(x->rd);
		if (p != REG.end()) REG.erase(x->rd);
		if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
		else REG.insert(std::pair<int, int>(0, 0));
	}
	void jalr()
	{
		if (tmp2lock == 1)
			tmp2lock = 0;
		y->result = x->result;
		p = REG.find(x->rd);
		if (p != REG.end()) REG.erase(x->rd);
		if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
		else REG.insert(std::pair<int, int>(0, 0));
	}
};

class Stype
{
private:
	buffer *x, *y;
public:
	Stype(buffer *tmp1, buffer *tmp2) :x(tmp1), y(tmp2)
	{
		y->address = x->x1 + signedextend((x->imm7 << 5) + x->imm5, 12);
	}
	void excution()
	{
		if (y->s == SB)
			sb();
		else if (y->s == SH)
			sh();
		else if (y->s == SW)
			sw();
		y->rs2 = x->rs2;
	}
	void sb()
	{
		y->result = x->x2 & 255;
	}
	void sh()
	{
		y->result = x->x2 & 65535;
	}
	void sw()
	{
		y->result = x->x2;
	}
};

class Btype
{
private:
	buffer *x, *y;
	unsigned int t1;
	unsigned int t2;
public:
	Btype(buffer *tmp1, buffer *tmp2) :x(tmp1), y(tmp2)
	{
		t1 = x->x1;
		t2 = x->x2;
	}
	void excution()
	{
		if (y->b == BEQ)
			beq();
		else if (y->b == BNE)
			bne();
		else if (y->b == BLTU)
			bltu();
		else if (y->b == BGEU)
			bgeu();
		else if (y->b == BLT)
			blt();
		else if (y->b == BGE)
			bge();
		if (tmp2lock == 1)
			tmp2lock = 0;
	}
	void beq()
	{
		if (x->x1 == x->x2)
		{
			if (Beq < 3) Beq++;
		}
		else Beq = 0;
		if ((tmp - 4) == x->address&&x->x1 != x->x2)
		{
			pc = tmp2;
			id1 = 0;
		}
		else if (x->x1 == x->x2 && (tmp - 4) != x->address)
		{
			pc = x->address;
			id1 = 0;
		}
		else pc = tmp3;
	}
	void bne()
	{
		if (x->x1 != x->x2)
		{
			if (Bne < 3) Bne++;
		}
		else Bne = 0;
		if ((tmp - 4) == x->address&&x->x1 == x->x2)            //预测的是跳转
		{
			pc = tmp2;
			id1 = 0;
		}
		else if (x->x1 != x->x2 && (tmp - 4) != x->address)        //预测的不是跳转
		{
			pc = x->address;
			id1 = 0;
		}
		else pc = tmp3;
	}
	void bltu()
	{
		if (t1 < t2)
		{
			if (Bltu < 3) Bltu++;
		}
		else Bltu = 0;
		if (t1 >= t2 && (tmp - 4) == x->address)
		{
			pc = tmp2;
			id1 = 0;
		}
		else if (t1 < t2 && (tmp - 4) != x->address)
		{
			pc = x->address;
			id1 = 0;
		}
		else  pc = tmp3;

	}
	void bgeu()
	{
		if (t1 >= t2)
		{
			if (Bgeu < 3) Bgeu++;
		}
		else Bgeu = 0;
		if (t1 < t2 && (tmp - 4) == x->address)
		{
			pc = tmp2;
			id1 = 0;
		}
		else if (t1 >= t2 && (tmp - 4) != x->address)
		{
			pc = x->address;
			id1 = 0;
		}
		else pc = tmp3;
	}
	void blt()
	{
		if (x->x1 < x->x2)
		{
			if (Blt < 3) Blt++;
		}
		else Blt = 0;
		if (x->x1 >= x->x2 && (tmp - 4) == x->address)
		{
			pc = tmp2;
			id1 = 0;
		}
		else if (x->x1 < x->x2 && (tmp - 4) != x->address)
		{
			pc = x->address;
			id1 = 0;
		}
		else pc = tmp3;
	}
	void bge()
	{
		if (x->x1 >= x->x2)
		{
			if (Bge)  Bge++;
		}
		else Bge = 0;
		if (x->x1 < x->x2 && (tmp - 4) == x->address)
		{
			pc = tmp2;
			id1 = 0;
		}
		else if (x->x1 >= x->x2 && (tmp - 4) != x->address)
		{
			pc = x->address;
			id1 = 0;
		}
		else pc = tmp3;
	}
};

class Utype
{
private:
	buffer *x, *y;
public:
	Utype(buffer *tmp1, buffer *tmp2) :x(tmp1), y(tmp2) {}
	void excution()
	{
		if (y->u == LUI) lui();
		else if (y->u == AUIPC)
			auipc();
		y->rd = x->rd;
	}
	void lui()         //在WB中实现
	{
		y->result = x->imm1 << 12;
		p = REG.find(x->rd);
		if (p != REG.end()) REG.erase(x->rd);
		if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
		else REG.insert(std::pair<int, int>(0, 0));
	}
	void auipc()
	{
		y->result = pc += x->imm1 << 12;
		p = REG.find(x->rd);
		if (p != REG.end()) REG.erase(x->rd);
		if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
		else REG.insert(std::pair<int, int>(0, 0));
	}
};

class Jtype
{
private:
	buffer *x, *y;
public:
	Jtype(buffer *tmp1, buffer *tmp2) :x(tmp1), y(tmp2) {}
	void excution()
	{
		jal();
		y->rd = x->rd;
	}
	void jal()
	{
		if (tmp2lock == 1)
			tmp2lock = 0;
		y->result = x->result;
		p = REG.find(x->rd);
		if (p != REG.end()) REG.erase(x->rd);
		if (x->rd != 0) REG.insert(std::pair<int, int>(x->rd, y->result));
		else REG.insert(std::pair<int, int>(0, 0));
	}
};
class EX
{
private:
	buffer *in, *out;
public:
	EX(buffer *tmp1, buffer *tmp2) :in(tmp1), out(tmp2) {}
	void excution()
	{
		out->x = in->x;
		switch (in->x & 127)
		{
		case 0x37:case 0x17:out->type = 'U'; judgeutype(); {Utype f(in, out); f.excution(); }break;
		case 0x6F:out->type = 'J'; judgejtype(); {Jtype f(in, out); f.excution(); }break;
		case 0x63:out->type = 'B'; judgebtype(); {Btype f(in, out); f.excution(); }break;
		case 0x23:out->type = 'S'; judgestype(); {Stype f(in, out); f.excution(); }break;
		case 0x13:case 0x67:case 0x3:out->type = 'I'; judgeitype(); {Itype f(in, out); f.excution(); }break;
		case 0x33:out->type = 'R'; judgertype(); {Rtype f(in, out); f.excution(); }break;
		}
		if (M1e == 0) M1e = 1;
	}
	void judgertype()
	{
		switch (in->func3)
		{
		case 0: {if (in->func7 == 0)out->r = ADD; else out->r = SUB; }break;
		case 1:out->r = SLL; break;
		case 2:out->r = SLT; break;
		case 3:out->r = SLTU; break;
		case 4:out->r = XOR; break;
		case 5: {if (in->func7 == 0)out->r = SRL; else out->r = SRA; }break;
		case 6:out->r = OR; break;
		case 7:out->r = AND; break;
		}
	}
	void judgeitype()
	{
		if (in->opcode == 3)
			switch (in->func3)
			{
			case 0:out->i = LB; break;
			case 1:out->i = LH; break;
			case 2:out->i = LW; break;
			case 4:out->i = LBU; break;
			case 5:out->i = LHU; break;
			}
		else if (in->opcode == 0x67)
			out->i = JALR;
		else if (in->opcode == 0x13)
			switch (in->func3)
			{
			case 0:out->i = ADDI; break;
			case 2:out->i = SLTI; break;
			case 3:out->i = SLTIU; break;
			case 4:out->i = XORI; break;
			case 6:out->i = ORI; break;
			case 7:out->i = ANDI; break;
			case 1:out->i = SLLI; break;
			case 5: {if (in->func7 == 0)out->i = SRLI; else out->i = SRAI; }break;
			}
	}
	void judgestype()
	{
		switch (in->func3)
		{
		case 0:out->s = SB; break;
		case 1:out->s = SH; break;
		case 2:out->s = SW; break;
		}
	}
	void judgebtype()
	{
		switch (in->func3)
		{
		case 0:out->b = BEQ; break;
		case 1:out->b = BNE; break;
		case 4:out->b = BLT; break;
		case 5:out->b = BGE; break;
		case 6:out->b = BLTU; break;
		case 7:out->b = BGEU; break;
		}
	}
	void judgeutype()
	{
		if (in->opcode == 0x17)
			out->u = AUIPC;
		else
			out->u = LUI;
	}
	void judgejtype()
	{
		out->j = JAL;
	}
};

#endif
