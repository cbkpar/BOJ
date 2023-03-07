#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	long long lSum = 0;
	vector<pair<int, int>> vecAns;
	while (iN--)
	{
		int iL;
		cin >> iL;
		int iMax = -100000;
		int iAnsLeft = -1;
		int iAnsRight = -1;
		int iLeft = 0;
		int iSum = 0;
		for (int i = 0; i < iL; ++i)
		{
			int iNum;
			cin >> iNum;
			if (iSum <= 0)
			{
				iLeft = i;
				iSum = 0;
			}
			iSum += iNum;
			if (iMax < iSum)
			{
				iMax = iSum;
				iAnsLeft = iLeft;
				iAnsRight = i;
			}
			else if (iMax == iSum && (iAnsRight - iAnsLeft) > (i - iLeft))
			{
				iAnsLeft = iLeft;
				iAnsRight = i;
			}
		}
		lSum += iMax;
		vecAns.push_back({ iAnsLeft + 1,iAnsRight + 1 });
	}
	cout << lSum << "\n";
	for (auto& Ans : vecAns)
	{
		cout << Ans.first << " " << Ans.second << "\n";
	}
	return 0;
}
