#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iS, iR;
	cin >> iN >> iS >> iR;

	vector<bool> vecPossible((iN + 2), true);

	vector<int> vecS(iS, 0);
	for (int i = 0; i < iS; ++i) cin >> vecS[i];
	for (int i = 0; i < iS; ++i) vecPossible[vecS[i]] = false;

	vector<int> vecR;
	for (int i = 0; i < iR; ++i)
	{
		int iNum;
		cin >> iNum;
		if (!vecPossible[iNum])
		{
			vecPossible[iNum] = true;
		}
		else
		{
			vecR.push_back(iNum);
		}
	}
	sort(vecR.begin(), vecR.end());
	for (int iPos : vecR)
	{
		if (!vecPossible[iPos - 1])
		{
			vecPossible[iPos - 1] = true;
		}
		else if (!vecPossible[iPos + 1])
		{
			vecPossible[iPos + 1] = true;
		}
	}
	int iCount = 0;
	for (int i = 1; i <= iN; ++i)
	{
		if (!vecPossible[i])
		{
			++iCount;
		}
	}

	cout << iCount << "\n";
	return 0;
}
