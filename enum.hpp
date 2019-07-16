#ifndef _ENUM_H
#define _ENUM_H
#include"memory.hpp"
#include"registor.hpp"
#include<map>
enum Uoperation { AUIPC, LUI };
enum Joperation { JAL };
enum Boperation { BEQ, BNE, BLT, BGE, BLTU, BGEU };
enum Soperation { SB, SH, SW };
enum Ioperation { LB, LH, LW, LBU, LHU, JALR, ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI };
enum Roperation { ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND };
int pc = 0;
bool M1g = 0;        //开始指令的锁
bool M1e = 0;
bool M1q = 0;
bool M1d = 0;
bool End = 0;       //结束指令的锁
bool id1 = 1;        //id的锁
bool id2 = 1;
bool id3 = 1;
bool id4 = 1;
int Beq = 0;        //Btype执行语句执行次数
int Bne = 0;
int Bltu = 0;
int Bgeu = 0;
int Blt = 0;
int Bge = 0;
int tmp = 0;       //暂存pc+4
int tmp2 = 0;      //pc被改变之前的pc值
bool tmp2lock = 0;
int tmp3 = 0;
std::map<int, int> REG;
std::map<int, int>::iterator p;
int signedextend(int x, int bits)
{
	if (x >> (bits - 1) == 1)
	{
		x |= ((0xffffffff >> bits) << bits);
	}
	return x;
}
#endif // _ENUM_H
