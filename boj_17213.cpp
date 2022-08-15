#include <iostream>

using namespace std;

void dfs(int iN, int iK, int iLast, int& iAnswer)
{
	if (iN == iK)
	{
		++iAnswer;
		return;
	}
	for (int i = 0; i <= iLast; ++i)
	{
		dfs(iN, iK + 1, iLast - i, iAnswer);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int iN, iM;
	cin >> iN >> iM;
	int iAnswer = 0;
	dfs(iN, 1, iM - iN, iAnswer);
	cout << iAnswer << "\n";
	return 0;
}
