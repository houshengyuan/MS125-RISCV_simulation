#ifndef _REGISTOR_H
#define _REGISTOR_H
///**********
const int regnum = 32;
class registor
{
public:
	int REG[regnum];
	registor()
	{
		for (int i = 0; i < regnum; i++)
			REG[i] = 0;
	}
	int &operator[](int num)
	{
		return REG[num];
	}
};
registor a;
#endif
