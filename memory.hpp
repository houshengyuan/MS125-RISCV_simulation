#ifndef _MEMORY_H
#define _MEMORY_H
const int memspace = 0x3fffff;
class memory
{
public:
	unsigned char *val;
	memory()
	{
		val = new unsigned char[memspace];
	}
	unsigned char operator[](int num)
	{
		return val[num];
	}
	memory & operator=(unsigned char *s)
	{
		for (int i = 0; i < memspace; i++)
			val[i] = s[i];
		return *this;
	}
};
static unsigned char S[0x3fffff] = { '\0' };
memory b;
#endif
