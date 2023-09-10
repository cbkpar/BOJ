#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iQ, iC;
	cin >> iN >> iQ >> iC;

	vector<int> vecCost(iN + 1, 0);
	for (int i = 1; i <= iN; ++i) cin >> vecCost[i];

	int iBackCap = 0;
	int iFrontCap = 0;
	deque<int> dBack;
	deque<int> dFront;
	int iNow = 0;

	while (iQ--)
	{
		string strCommand;
		cin >> strCommand;

		if (strCommand == "B")
		{
			if (!dBack.empty())
			{
				if (iNow != 0)
				{
					dFront.push_front(iNow);
					iFrontCap += vecCost[iNow];
				}
				iNow = dBack.back();
				dBack.pop_back();
				iBackCap -= vecCost[iNow];
			}
		}
		else if (strCommand == "F")
		{
			if (!dFront.empty())
			{
				if (iNow != 0)
				{
					dBack.push_back(iNow);
					iBackCap += vecCost[iNow];
				}
				iNow = dFront.front();
				dFront.pop_front();
				iFrontCap -= vecCost[iNow];
			}
		}
		else if (strCommand == "A")
		{
			int iRoute;
			cin >> iRoute;

			if (iNow != 0)
			{
				dBack.push_back(iNow);
				iBackCap += vecCost[iNow];
			}
			iNow = iRoute;
			while (!dFront.empty())
			{
				dFront.pop_front();
			}
			iFrontCap = 0;
			while (iBackCap + vecCost[iNow] > iC)
			{
				int iNext = dBack.front();
				iBackCap -= vecCost[iNext];
				dBack.pop_front();
			}
		}
		else if (strCommand == "C")
		{
			int iSize = dBack.size();
			int iTemp = -1;
			while (iSize--)
			{
				int iNext = dBack.front();
				iBackCap -= vecCost[iNext];
				dBack.pop_front();
				if (iNext != iTemp)
				{
					dBack.push_back(iNext);
					iBackCap += vecCost[iNext];
				}
				iTemp = iNext;
			}
		}
	}
	cout << iNow << "\n";
	if (dBack.empty())
	{
		cout << "-1" << "\n";
	}
	else
	{
		int iSize = dBack.size();
		for (int i = 0; i < iSize; ++i)
		{
			int iNext = dBack.back();
			dBack.pop_back();
			cout << iNext << (i == iSize - 1 ? "\n" : " ");
		}
	}
	if (dFront.empty())
	{
		cout << "-1" << "\n";
	}
	else
	{
		int iSize = dFront.size();
		for (int i = 0; i < iSize; ++i)
		{
			int iNext = dFront.front();
			dFront.pop_front();
			cout << iNext << (i == iSize - 1 ? "\n" : " ");
		}
	}
	return 0;
}
