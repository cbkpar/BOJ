#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int CalcLevel(const string& grade)
{
	int iLevel = 0;
	if (grade[0] == 'B') iLevel = 10000;
	if (grade[0] == 'S') iLevel = 20000;
	if (grade[0] == 'G') iLevel = 30000;
	if (grade[0] == 'P') iLevel = 40000;
	if (grade[0] == 'D') iLevel = 50000;

	int iTemp = 0;
	int iSize = grade.length();
	for (int i = 1; i < iSize; ++i)
	{
		iTemp *= 10;
		iTemp += grade[i] - '0';
	}
	return iLevel + (1000 - iTemp);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<pair<int, string>> vecGrade(iN, { 0,"" });
	vector<int> vecScore(iN, 0);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecGrade[i].second;
		vecGrade[i].first = CalcLevel(vecGrade[i].second);
		vecScore[i] = vecGrade[i].first;
	}
	sort(vecScore.begin(), vecScore.end());
	vector<int> vecAns;
	for (int i = 0; i < iN; ++i)
	{
		if (vecGrade[i].first != vecScore[i])
		{
			vecAns.push_back(i);
		}
	}
	if (vecAns.empty())
	{
		cout << "OK\n";
	}
	else
	{
		cout << "KO\n";
		cout << vecGrade[vecAns[1]].second << " " << vecGrade[vecAns[0]].second << "\n";
		return 0;
	}

	return 0;
}
