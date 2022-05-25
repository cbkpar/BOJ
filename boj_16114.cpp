#include <iostream>

using namespace std;

int main()
{
	int iX, iN;
	cin >> iX >> iN;
	if (0 == iN)
	{
		if (0 < iX)
		{
			cout << "INFINITE" << endl;
			return 0;
		}
		else
		{
			cout << "0" << endl;
			return 0;
		}
	}
	if (1 == iN)
	{
		int asdf = 1;
		if (0 > iX)
		{
			cout << "INFINITE" << endl;
			return 0;
		}
		else
		{
			cout << "0" << endl;
			return 0;
		}
	}
	if (0 != iN % 2)
	{
		cout << "ERROR" << endl;
		return 0;
	}
	int iAnswer = 0;
	iN /= 2;
	iX -= iN;
	while (0 < iX)
	{
		++iAnswer;
		iX -= iN;
	}
	cout << iAnswer << endl;
	return 0;
}
