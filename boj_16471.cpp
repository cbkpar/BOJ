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

	vector<int> vecA(iN, 0);
	vector<int> vecB(iN, 0);

	for (int i = 0;i < iN;++i) cin >> vecA[i];
	for (int i = 0;i < iN;++i) cin >> vecB[i];

	sort(vecA.begin(), vecA.end());
	sort(vecB.begin(), vecB.end());

	int iIndex = 0;
	int iCount = 0;

	for (int i = 0;i < iN;++i)
	{
		while (iIndex < iN)
		{
			if (vecA[i] < vecB[iIndex++])
			{
				++iCount;
				break;
			}
		}
	}

	if (iCount * 2 >= (iN + 1))
	{
		cout << "YES" << "\n";
	}
	else
	{
		cout << "NO" << "\n";
	}

	return 0;
}
