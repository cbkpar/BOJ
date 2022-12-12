#include <iostream>
#include <set>

using namespace std;

int arrNumber[20] = { 0, };
int iN;
set<int> setNumber;

void dfs(int iNum, int iSum)
{
	if (iNum == iN)
	{
		if (iSum == 0) return;
		if (setNumber.find(iSum) == setNumber.end())
		{
			setNumber.emplace(iSum);
		}
	}
	else
	{
		dfs(iNum + 1, iSum + arrNumber[iNum]);
		dfs(iNum + 1, iSum);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iSum = 0;

	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		cin >> arrNumber[i];
		iSum += arrNumber[i];
	}
	dfs(0, 0);
	iSum -= setNumber.size();
	cout << iSum << "\n";
	return 0;
}
