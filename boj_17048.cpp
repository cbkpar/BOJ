#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<int> vecA(iN, 0);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecA[i];
	}
	vector<int> vecB(iN, 0);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecB[i];
	}

	vector<int> vecC(iN, 0);
	for (int i = 0; i < iN; ++i)
	{
		vecC[i] = vecA[i] - vecB[i];
	}
	sort(vecC.begin(), vecC.end());

	int iBefore = vecC[0];
	int iAns = 1;
	int iNow = 1;
	for (int i = 1; i < iN; ++i)
	{
		if (vecC[i - 1] == vecC[i])
		{
			++iNow;
		}
		else
		{
			iNow = 1;
		}
		iAns = max(iAns, iNow);
	}
	cout << iAns << "\n";
	return 0;
}
