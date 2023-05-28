#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void CalcScore(const string& strScore, int& iScoreA, int& iScoreB)
{
	int iTemp = 0;
	int iIndex = 0;
	while (true)
	{
		if (strScore[iIndex] == '/')
		{
			iScoreA = iTemp;
			iTemp = 0;
			++iIndex;
			break;
		}
		iTemp *= 10;
		iTemp += strScore[iIndex] - '0';
		++iIndex;
	}
	int iSize = strScore.size();
	while (true)
	{
		if (iIndex == iSize)
		{
			iScoreB = iTemp;
			break;
		}
		iTemp *= 10;
		iTemp += strScore[iIndex] - '0';
		++iIndex;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecWeight(4, 0);
	vector<pair<int, int>> vecTotalScore(4, { 0,0 });
	for (int i = 0; i < 4; ++i) cin >> vecWeight[i];

	int iN;
	cin >> iN;
	while (iN--)
	{
		string strSubject, strRound, strScore;
		cin >> strSubject >> strRound >> strScore;

		int iScoreA, iScoreB;
		CalcScore(strScore, iScoreA, iScoreB);
		int iIndex = -1;
		if (strSubject == "Lab") iIndex = 0;
		if (strSubject == "Hw") iIndex = 1;
		if (strSubject == "Proj") iIndex = 2;
		if (strSubject == "Exam") iIndex = 3;
		vecTotalScore[iIndex].first += iScoreA;
		vecTotalScore[iIndex].second += iScoreB;
	}

	double dAns = 0;
	for (int i = 0; i < 4; ++i)
	{
		dAns += vecWeight[i] * ((double)vecTotalScore[i].first / (double)vecTotalScore[i].second);
	}
	cout << (int)dAns << "\n";
	return 0;
}
