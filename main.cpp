#include <iostream>
#include"EX.hpp"
#include"ID.hpp"
#include"IF.hpp"
#include"MA.hpp"
#include"memory.hpp"
#include"registor.hpp"
#include"WB.hpp"
#include"enum.hpp"
#include"buffer.hpp"
#include<map>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int sign = 0;
	char t1, t2;
	int z1, z2;
	while (cin >> t1)
	{
		if (t1 == '@')
		{
			sign = 0;
			for (int i = 0; i < 8; i++)
			{
				cin >> t2;
				if (t2 >= 48 && t2 <= 57)
					z2 = t2 - '0';
				else
					z2 = t2 - 'A' + 10;
				sign = (sign << 4) + z2;
			}
		}
		else
		{
			cin >> t2;
			if (t1 >= 48 && t1 <= 57)
				z1 = t1 - '0';
			else
				z1 = t1 - 'A' + 10;
			if (t2 >= 48 && t2 <= 57)
				z2 = t2 - '0';
			else
				z2 = t2 - 'A' + 10;
			S[sign++] = (unsigned char)((z1 << 4) + z2);
		}
	}
	b = S;
	buffer A, B, C, D;
	IF c(&A);
	ID d(&A, &B);
	EX q(&B, &C);
	MA e(&C, &D);
	WB g(&D);
	while (true)
	{
		if (M1g == 1 && id4 == 1)
			g.writeback();
		if (M1e == 1 && id3 == 1)
			e.memoryaccess();
		if (End == 1)
		{
			g.writeback();
			return 0;
		}
		if (M1q == 1 && id2 == 1)
			q.excution();
		if (M1d == 1 && id1 == 1)
			d.decode();
		c.readinst();
	}
	return 0;
}
