#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<int> vecNum(iN + 1, -1);
	for (int i = 1; i <= iN; ++i) cin >> vecNum[i];

	int iAns = 0;
	for (int i = 0; i <= iN; ++i)
	{
		vector<int> vecTemp;
		int iCount = 0;
		int iMax = 0;
		int iBefore = -2;
		for (int j = 1; j <= iN; ++j)
		{
			if (vecNum[j] != vecNum[i])
			{
				vecTemp.push_back(vecNum[j]);
			}
		}
		int iSize = vecTemp.size();
		for (int j = 0; j < iSize; ++j)
		{
			if (iBefore == vecTemp[j])
			{
				++iCount;
			}
			else
			{
				iBefore = vecTemp[j];
				iCount = 1;
			}
			iMax = max(iMax, iCount);
		}
		iAns = max(iAns, iMax);
	}

	cout << iAns << "\n";
	return 0;
}
