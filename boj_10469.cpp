#include <iostream>
#include <cstring>

using namespace std;

int arrMap[8][8];
int arrDX[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int arrDY[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

bool CheckArea(int _iY, int _iX, int _iN)
{
	while (true)
	{
		_iX += arrDX[_iN];
		_iY += arrDY[_iN];
		if (_iX < 0 || _iX >= 8 || _iY < 0 || _iY >= 8)
		{
			return true;
		}
		if (1 == arrMap[_iY][_iX])
		{
			return false;
		}
	}
	return true;
}

bool CheckMap()
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (0 == arrMap[i][j])
			{
				continue;
			}
			for (int k = 0; k < 8; ++k)
			{
				if (!CheckArea(i, j, k))
				{
					return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	int iSum = 0;
	for (int i = 0; i < 8; ++i)
	{
		char szStr[9];
		cin >> szStr;
		for (int j = 0; j < 8; ++j)
		{
			arrMap[i][j] = szStr[j] == '*' ? 1 : 0;
			iSum += arrMap[i][j];
		}
	}
	if (CheckMap() && iSum == 8)
	{
		cout << "valid" << endl;
	}
	else
	{
		cout << "invalid" << endl;
	}
	return 0;
}
