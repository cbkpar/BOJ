#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int iN;
vector<int> vecNum;
vector<int> vecAnswer;
vector<bool> vecUsed;
vector<bool> vecVisited;
bool bFound = false;

void BackTracking(int iK)
{
	if (bFound) return;
	if (iK == iN * 2)
	{
		bFound = true;
		return;
	}
	if (vecVisited[iK])
	{
		BackTracking(iK + 1);
		return;
	}
	for (int i = 0; i < iN; ++i)
	{
		if (!vecUsed[i] && iK + vecNum[i] + 1 < iN * 2 && !vecVisited[iK + vecNum[i] + 1])
		{
			vecUsed[i] = true;
			vecVisited[iK + vecNum[i] + 1] = true;
			vecAnswer[iK] = vecAnswer[iK + vecNum[i] + 1] = vecNum[i];
			BackTracking(iK + 1);
			if (bFound) return;
			vecVisited[iK + vecNum[i] + 1] = false;
			vecUsed[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iN;
	vecNum.resize(iN);
	vecAnswer.resize(iN * 2);
	vecVisited.resize(iN * 2);
	vecUsed.resize(iN);
	for (int i = 0; i < iN * 2; ++i) vecVisited[i] = false;
	for (int i = 0; i < iN; ++i) vecUsed[i] = false;

	for (int i = 0; i < iN; ++i)
	{
		cin >> vecNum[i];
	}
	sort(vecNum.begin(), vecNum.end());
	BackTracking(0);
	if (bFound)
	{
		for (int i = 0; i < iN * 2; ++i)
		{
			cout << vecAnswer[i] << (i == iN * 2 - 1 ? "\n" : " ");
		}
	}
	else
	{
		cout << "-1\n";
	}
	return 0;
}
