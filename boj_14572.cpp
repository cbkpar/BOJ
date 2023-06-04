#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK, iD;
	cin >> iN >> iK >> iD;

	vector<pair<int, int>> vecStudent(iN, { 0,0 });
	vector<vector<int>> vecAlgo(iN, vector<int>());
	for (int i = 0; i < iN; ++i)
	{
		int iCount;
		cin >> iCount >> vecStudent[i].first;
		vecStudent[i].second = i;
		while (iCount--)
		{
			int iAlgo;
			cin >> iAlgo;
			vecAlgo[i].push_back(iAlgo - 1);
		}
	}
	sort(vecStudent.begin(), vecStudent.end());

	int iLeft = 0;
	int iRight = 0;
	int iAns = 0;
	vector<int> vecAlgoCount(iK, 0);
	while (iRight < iN)
	{
		for (int iAlgo : vecAlgo[vecStudent[iRight].second])
		{
			++vecAlgoCount[iAlgo];
		}
		while (vecStudent[iRight].first - vecStudent[iLeft].first > iD)
		{
			for (int iAlgo : vecAlgo[vecStudent[iLeft].second])
			{
				--vecAlgoCount[iAlgo];
			}
			++iLeft;
		}

		int iStudent = iRight - iLeft + 1;
		int iCount = 0;
		for (int i = 0; i < iK; ++i)
		{
			if (vecAlgoCount[i] != 0 && vecAlgoCount[i] < iStudent)
			{
				++iCount;
			}
		}
		iAns = max(iAns, iCount * iStudent);
		++iRight;
	}
	cout << iAns << "\n";
	return 0;
}
