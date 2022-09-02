#include <iostream>

using namespace std;

bool matNumber[4][10];
int arrCount[10];

bool Straight()
{
	int iCount = 0;
	for (int i = 1; i <= 9; ++i)
	{
		bool bIsExist = false;
		for (int j = 0; j < 4; ++j)
		{
			if (matNumber[j][i])
			{
				bIsExist = true;
			}
		}
		if (bIsExist)
		{
			++iCount;
			if (5 == iCount)
			{
				return true;
			}
		}
		else
		{
			iCount = 0;
		}
	}
	return false;
}

bool Flush()
{
	for (int i = 0; i < 4; ++i)
	{
		int iCount = 0;
		for (int j = 1; j <= 9; ++j)
		{
			if (matNumber[i][j])
			{
				++iCount;
			}
		}
		if (iCount == 5)
		{
			return  true;
		}
	}
	return false;
}

int Solve()
{
	bool bIsStraight = Straight();
	bool bIsFlush = Flush();
	//900
	if (bIsStraight && bIsFlush)
	{
		for (int i = 9; i >= 1; --i)
		{
			if (arrCount[i])
			{
				return 900 + i;
			}
		}
	}
	//800
	for (int i = 9; i >= 1; --i)
	{
		if (arrCount[i] == 4)
		{
			return 800 + i;
		}
	}
	//700
	for (int i = 9; i >= 1; --i)
	{
		if (arrCount[i] == 3)
		{
			for (int j = 9; j >= 1; --j)
			{
				if (arrCount[j] == 2)
				{
					return 700 + i * 10 + j;
				}
			}
		}
	}
	//600
	if (bIsFlush)
	{
		for (int i = 9; i >= 1; --i)
		{
			if (arrCount[i] > 0)
			{
				return 600 + i;
			}
		}
	}
	//500
	if (bIsStraight)
	{
		for (int i = 9; i >= 1; --i)
		{
			if (arrCount[i] > 0)
			{
				return 500 + i;
			}
		}
	}
	//400
	for (int i = 9; i >= 1; --i)
	{
		if (arrCount[i] == 3)
		{
			return 400 + i;
		}
	}
	//300
	for (int i = 9; i >= 1; --i)
	{
		if (arrCount[i] == 2)
		{
			for (int j = i - 1; j >= 1; --j)
			{
				if (arrCount[j] == 2)
				{
					return 300 + i * 10 + j;
				}
			}
		}
	}
	//200
	for (int i = 9; i >= 1; --i)
	{
		if (arrCount[i] == 2)
		{
			return 200 + i;
		}
	}
	//100
	for (int i = 9; i >= 1; --i)
	{
		if (arrCount[i] > 0)
		{
			return 100 + i;
		}
	}
	return 0;
}

int main()
{
	for (int i = 0; i < 5; ++i)
	{
		char ch;
		int iNumber;
		cin >> ch >> iNumber;
		switch (ch)
		{
		case 'R':
			matNumber[0][iNumber] = true;
			break;
		case 'B':
			matNumber[1][iNumber] = true;
			break;
		case 'Y':
			matNumber[2][iNumber] = true;
			break;
		case 'G':
			matNumber[3][iNumber] = true;
			break;
		}
		++arrCount[iNumber];
	}
	cout << Solve() << endl;
	return 0;
}
