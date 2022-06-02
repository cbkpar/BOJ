#include <iostream>
#include <string>

using namespace std;

int arrMap[50][50];
int iSumCount[5] = { 0, };
int dR[4] = { 0, 0, 1, 1 };
int dC[4] = { 0, 1, 0 , 1 };

int CheckArea(int _iR, int _iC)
{
	int iSum = 0;
	for (int i = 0; i < 4; ++i)
	{
		int tR = _iR + dR[i];
		int tC = _iC + dC[i];
		switch (arrMap[tR][tC])
		{
		case 0:
			return -1;
			break;
		case 2:
			++iSum;
			break;
		default:
			break;
		}
	}
	return iSum;
}

int main()
{
	int iR, iC;
	cin >> iR >> iC;
	for (int i = 0; i < iR; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < iC; ++j)
		{
			switch (str[j])
			{
			case '#':
				arrMap[i][j] = 0;
				break;
			case '.':
				arrMap[i][j] = 1;
				break;
			case 'X':
				arrMap[i][j] = 2;
				break;
			default:
				break;
			}
		}
	}
	for (int i = 0; i < iR - 1; ++i)
	{
		for (int j = 0; j < iC - 1; ++j)
		{
			int iNum = CheckArea(i, j);
			if (-1 != iNum)
			{
				++iSumCount[iNum];
			}
		}
	}
	for (int i = 0; i < 5; ++i)
	{
		cout << iSumCount[i] << endl;
	}
	return 0;
}
