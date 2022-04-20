#include <iostream>

using namespace std;

bool bVisited[10];
int iArray[10];
int iAnswer, iLen, iLimit;

void dfs(int k, int sum)
{
	if (k == iLen)
	{
		if (sum < iLimit && sum > iAnswer)
		{
			iAnswer = sum;
		}
		return;
	}
	for (int i = 0; i < iLen; ++i)
	{
		if (!bVisited[i])
		{
			bVisited[i] = true;
			dfs(k + 1, sum * 10 + iArray[i]);
			bVisited[i] = false;
		}

	}
}

int main()
{
	int iA;
	cin >> iA >> iLimit;

	int iTemp = iA;
	while (iTemp)
	{
		iArray[iLen++] = iTemp % 10;
		iTemp /= 10;
	}
	iAnswer = -1;
	for (int i = 0; i < iLen; ++i)
	{
		if (iArray[i] != 0)
		{
			bVisited[i] = true;
			dfs(1, iArray[i]);
			bVisited[i] = false;
		}
	}
	cout << iAnswer << endl;
	return 0;
}
