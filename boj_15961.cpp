#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iClass, iRange, iCoupon;
	cin >> iN >> iClass >> iRange >> iCoupon;

	queue<int> qNum;
	queue<int> qRest;
	int iMax = 1;
	int iNow = 1;
	vector<int> vecCount(iClass + 1, 0);
	vecCount[iCoupon] = 1;
	while (iN--)
	{
		int iNum;
		cin >> iNum;
		if (vecCount[iNum]++ == 0) ++iNow;
		qNum.push(iNum);
		if (qNum.size() > iRange)
		{
			int iTemp = qNum.front();
			qNum.pop();
			qRest.push(iTemp);
			if (--vecCount[iTemp] == 0) --iNow;
		}
		iMax = max(iMax, iNow);
	}
	while (!qRest.empty())
	{
		int iNum = qRest.front();
		qRest.pop();
		if (vecCount[iNum]++ == 0) ++iNow;
		qNum.push(iNum);
		if (qNum.size() > iRange)
		{
			int iTemp = qNum.front();
			qNum.pop();
			if (--vecCount[iTemp] == 0) --iNow;
		}
		iMax = max(iMax, iNow);
	}
	cout << iMax << "\n";
	return 0;
}
