#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	int iCountA = 0;
	vector<int> vecA(iN, 0);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecA[i];
		if (vecA[i] == 1)
		{
			++iCountA;
		}
	}
	int iCountB = 0;
	vector<int> vecB(iN, 0);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecB[i];
		if (vecB[i] == 1)
		{
			++iCountB;
		}
	}

	int iSame = 0;
	int iDiff = 0;
	for (int i = 0; i < iN; ++i)
	{
		if (vecA[i] == vecB[i])
		{
			++iSame;
		}
		else
		{
			++iDiff;
		}
	}

	int iAns = iDiff;
	if (iCountA == iN)
	{
		iAns = min(iAns, iCountB + 1);
	}
	else
	{
		iAns = min(iAns, iN-iCountB + 1);
		iAns = min(iAns, iCountB + 2);
	}

	cout << iAns << "\n";
	return 0;
}
