#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

uint32_t popcnt(uint32_t x)
{
	x -= ((x >> 1) & 0x55555555);
	x = (((x >> 2) & 0x33333333) + (x & 0x33333333));
	x = (((x >> 4) + x) & 0x0f0f0f0f);
	x += (x >> 8);
	x += (x >> 16);
	return x & 0x0000003f;
}
uint32_t clz(uint32_t x)
{
	x |= (x >> 1);
	x |= (x >> 2);
	x |= (x >> 4);
	x |= (x >> 8);
	x |= (x >> 16);
	return 32 - popcnt(x);
}
uint32_t ctz(uint32_t x)
{
	return popcnt((x & -x) - 1);
}

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iNow = (1 << 10) - 1;

	string strCommand;
	cin >> strCommand;

	for (char ch : strCommand)
	{
		if (ch == 'L')
		{
			iNow -= 1 << ctz(iNow);
		}
		else if (ch == 'R')
		{
			iNow -= 1 << (31 - clz(iNow));
		}
		else
		{
			iNow |= (1 << (ch - '0'));
		}
	}
	iNow = 1023 - iNow;
	for (int i = 0; i < 10; ++i)
	{
		cout << (iNow % 2);
		iNow /= 2;
	}
	cout << "\n";

	return 0;
}
