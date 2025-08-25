#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int iN, iM;
	cin >> iN >> iM;

	vector<int> vecLevel(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecLevel[i];
	}
	sort(vecLevel.begin(), vecLevel.end());

	vector<pair<int, int>> vecPeople(iM, { 0,0 });
	for (int i = 0;i < iM;++i)
	{
		cin >> vecPeople[i].first;
		vecPeople[i].second = i;
	}
	sort(vecPeople.begin(), vecPeople.end());

	vector<int> vecAns(iM, 0);

	int iLevel = 0;
	int iSize = 0;
	for (int i = 0;i < iM;++i)
	{
		while (iLevel < iN)
		{
			if (vecPeople[i].first < vecLevel[iLevel]) break;
			++iLevel;
			if ((3 * (iSize + 1) * (iSize)) + 1 <= iLevel)
			{
				++iSize;
			}
		}
		vecAns[vecPeople[i].second] = iSize;
	}

	for (int i = 0;i < iM;++i)
	{
		cout << vecAns[i] << (i == iM - 1 ? "\n" : " ");
	}
	return 0;
}
