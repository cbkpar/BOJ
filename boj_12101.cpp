#include <iostream>

using namespace std;

int iN, iK;
int arrNumber[11] = { 0, };
bool bCheck = false;

void dfs(int iOrder, int iRemain)
{
	if (iK < 0 || iOrder > 11)
	{
		return;
	}
	if (iRemain == 0)
	{
		--iK;
	}
	if (iK == 0)
	{
		cout << arrNumber[0];
		for (int i = 1; i < iOrder; ++i)
		{
			cout << "+" << arrNumber[i];
		}
		--iK;
		bCheck = true;
		return;
	}
	for (int i = 1; i <= 3; ++i)
	{
		if (iRemain >= i)
		{   
			arrNumber[iOrder] = i;
			dfs(iOrder + 1, iRemain - i);
		}
	}
}

int main()
{
	cin >> iN >> iK;
	dfs(0, iN);
	if (!bCheck)
	{
		cout << "-1" << endl;
	}
	return 0;
}
