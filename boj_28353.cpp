#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	vector<int> vecA;
	vector<int> vecB;

	for (int i = 0; i < iN; ++i)
	{
		int iWeight;
		cin >> iWeight;
		if (iWeight > iK / 2)
		{
			vecB.push_back(iWeight);
		}
		else
		{
			vecA.push_back(iWeight);
		}
	}
	sort(vecA.begin(), vecA.end());
	sort(vecB.begin(), vecB.end());

	int iAns = 0;
	int iSizeA = vecA.size();
	int iRest = iSizeA;
	int iIndex = iSizeA-1;
	int iSizeB = vecB.size();

	for (int i = 0; i < iSizeB; ++i)
	{
		while (iIndex >= 0)
		{
			if (vecA[iIndex] + vecB[i] <= iK)
			{
				--iRest;
				--iIndex;
				++iAns;
				break;
			}
			else
			{
				--iIndex;
			}
		}
	}
	iAns += iRest / 2;
	cout << iAns << "\n";
	return 0;
}
