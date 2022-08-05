#include <iostream>

using namespace std;

int main()
{
	int iT;
	cin >> iT;
	while (iT--)
	{
		int iNumber, iScoreStrategy, iScoreManage, iScoreSkill;
		cin >> iNumber >> iScoreStrategy >> iScoreManage >> iScoreSkill;
		bool bIsPass = true;
		int iSumScore = iScoreStrategy + iScoreManage + iScoreSkill;
		if (55 > iSumScore)
		{
			bIsPass = false;
		}
		if (11 > iScoreStrategy || 8 > iScoreManage || 12 > iScoreSkill)
		{
			bIsPass = false;
		}
		cout << iNumber << " " << iSumScore << " " << (bIsPass ? "PASS" : "FAIL") << endl;
	}
}
