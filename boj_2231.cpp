#include <iostream>
#include <memory.h>

using namespace std;

typedef unsigned int _uint;

int CalcSeparteSum(_uint _iN)
{
	_uint iSum = _iN;
	_uint iTemp = _iN;
	while (iTemp)
	{
		iSum += iTemp % 10;
		iTemp /= 10;
	}
	return iSum;
}

int main()
{
	_uint iN;
	cin >> iN;
	_uint* arrNumber = new _uint[iN + 1];
	memset(arrNumber, 0, sizeof(_uint) * (iN + 1));

	for (_uint i = 1; i <= iN; ++i)
	{
		_uint iNext = CalcSeparteSum(i);
		if (iNext <= iN && arrNumber[iNext] == 0)
		{
			arrNumber[iNext] = i;
		}
	}
	cout << arrNumber[iN] << endl;
	return 0;
}
