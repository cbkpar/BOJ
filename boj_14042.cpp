#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iType;
	cin >> iType;

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


	if (iType == 1)
	{
		sort(vecA.begin(), vecA.end());
		sort(vecB.begin(), vecB.end());
	}
	else
	{
		sort(vecA.begin(), vecA.end());
		sort(vecB.begin(), vecB.end(), greater<>());
	}

	int iAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		iAns += max(vecA[i], vecB[i]);
	}

	cout << iAns << "\n";
	return 0;
}
