#ifndef _WB_H
#define _WB_H
#include"EX.hpp"
#include"ID.hpp"
#include"buffer.hpp"
#include"enum.hpp"
#include"memory.hpp"
#include<assert.h>
#include"registor.hpp"
class WB
{
private:
	buffer *in;
public:
	WB(buffer *tmp1) :in(tmp1) {}
	void writeback()
	{
		if (in->type != 'S'&&in->type != 'B')
		{
			if (in->rd == 0)
			{
				p = REG.find(in->rd);
				if (p != REG.end() && p->second == in->result)
					REG.erase(p);
				return;
			}
			a[in->rd] = in->result;
			p = REG.find(in->rd);
			if (p != REG.end() && p->second == in->result)
				REG.erase(p);
		}
	}
};

#endif // _WB_H
