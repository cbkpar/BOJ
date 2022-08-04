#include <iostream>
#include <memory.h>

#define Safe_Release_Array(p) if(p){delete[] p;p=nullptr;}

using namespace std;

int CalcAverage(int* _arr, int _iSize)
{
	int iSum = 0;
	for (int i = 0; i <= 8000; ++i)
	{
		iSum += _arr[i] * (i - 4000);
	}
	int iTemp = iSum % _iSize;
	iSum /= _iSize;
	if (iTemp < 0)
	{
		iTemp += _iSize;
		iSum -= 1;
	}
	iSum += (iTemp * 2 >= _iSize) ? 1 : 0;
	return iSum;
}

int CalcMedian(int* _arr, int _iSize)
{
	int iN = _iSize / 2 + 1;
	for (int i = 0; i <= 8000; ++i)
	{
		if (iN <= _arr[i])
		{
			return i - 4000;
		}
		iN -= _arr[i];
	}
	return -1;
}

int CalcMode(int* _arr)
{
	int iMaxCount = 0;
	for (int i = 0; i <= 8000; ++i)
	{
		if (iMaxCount < _arr[i])
		{
			iMaxCount = _arr[i];
		}
	}
	int iNumber = -4001;
	for (int i = 0; i <= 8000; ++i)
	{
		if (iMaxCount == _arr[i])
		{
			if (iNumber != -4001)
			{
				return i - 4000;
			}
			iNumber = i - 4000;
		}
	}
	return iNumber;
}

int CalcRange(int* _arr)
{
	int iMin = 4001;
	int iMax = -4001;
	for (int i = 0; i <= 8000; ++i)
	{
		if (0 < _arr[i])
		{
			iMin = (i - 4000 < iMin) ? i - 4000 : iMin;
			iMax = (i - 4000 > iMax) ? i - 4000 : iMax;
		}
	}
	return iMax - iMin;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int* arrNumber = new int[8001];
	memset(arrNumber, 0, sizeof(int) * 8001);
	int iN;
	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		int iNumber;
		cin >> iNumber;
		++arrNumber[iNumber + 4000];
	}
	cout << CalcAverage(arrNumber, iN) << endl;
	cout << CalcMedian(arrNumber, iN) << endl;
	cout << CalcMode(arrNumber) << endl;
	cout << CalcRange(arrNumber) << endl;
	Safe_Release_Array(arrNumber);
	return 0;
}
