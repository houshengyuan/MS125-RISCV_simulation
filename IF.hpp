#ifndef _IF_H
#define _IF_H
#include<iostream>
#include"enum.hpp"
#include"buffer.hpp"
///**********
class IF
{
public:
	buffer *out;
	IF(buffer *tmp) :out(tmp) {}
	void readinst()
	{
		int temp = (b[pc + 3] << 24) + (b[pc + 2] << 16) + (b[pc + 1] << 8) + b[pc];
		tmp = pc += 4;
		tmp3 = tmp;
		if ((temp & 127) == 0x6F)                //jal
		{
			if (tmp2lock == 0)
			{
				tmp2 = pc;
				tmp2lock = 1;
			}
			out->result = pc;
			pc += signedextend(((temp >> 21 & 1023) + ((temp >> 20 & 1) << 10) + ((temp >> 12 & 255) << 11) + (temp >> 31 << 19)) << 1, 21) - 4;
			tmp3 = pc;
		}
		else if ((temp & 127) == 0x67)           //jalr
		{
			if (tmp2lock == 0)
			{
				tmp2 = pc;
				tmp2lock = 1;
			}
			if ((out->x & 127) != 0x63 && (out->x & 127) != 0x23 && out->rd == (temp >> 15 & 31))  //µÈ´ýÏÐÖÃ
				pc = (a[out->rd] + (temp >> 20)) >> 1 << 1;
			else
			{
				p = REG.find(temp >> 15 & 31);
				if (p != REG.end()) pc = (p->second + (temp >> 20)) >> 1 << 1;
				else pc = (a[temp >> 15 & 31] + (temp >> 20)) >> 1 << 1;
			}
			out->result = pc + 4;
			tmp3 = pc;
		}
		else if ((temp & 127) == 0x63)
		{
			if (tmp2lock == 0)
			{
				tmp2 = pc;
				tmp2lock = 1;
			}
			int address = (((temp >> 31 << 11) + ((temp >> 7 & 1) << 10) + ((temp >> 25 & 63) << 4) + (temp >> 8 & 15)) << 1) + pc - 4;
			out->address = address;
			if ((temp >> 12 & 7) == 0)                 //beq
			{
				if (Beq == 3)
					pc = address;
			}
			else if ((temp >> 12 & 7) == 1)            //bne
			{
				if (Bne == 3)
					pc = address;
			}
			else if ((temp >> 12 & 7) == 4)            //blt
			{
				if (Blt == 3)
					pc = address;
			}
			else if ((temp >> 12 & 7) == 5)            //bge
			{
				if (Bge == 3)
					pc = address;
			}
			else if ((temp >> 12 & 7) == 6)            //bltu
			{
				if (Bltu == 3)
					pc = address;
			}
			else if ((temp >> 12 & 7) == 7)            //bgeu
			{
				if (Bgeu == 3)
					pc = address;
			}
		}
		out->x = temp;
		if (!M1d) M1d = 1;
		if (id1 == 0)
		{
			id1 = 1; id2 = 0;
			if (id3 == 0)
			{
				id3 = 1; id4 = 0;
			}
			else if (id4 == 0)
				id4 = 1;
		}
		else if (id2 == 0)
		{
			id2 = 1; id3 = 0;
			if (id4 == 0)
				id4 = 1;
		}
		else if (id3 == 0)
		{
			id3 = 1; id4 = 0;
		}
		else if (id4 == 0)
			id4 = 1;
	}
};
#endif
