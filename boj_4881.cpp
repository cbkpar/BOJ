#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int CalcDigitPow(int iN) {
	int iAcc = 0;
	while (iN > 0) {
		int iTemp = iN % 10;
		iAcc += iTemp * iTemp;
		iN /= 10;
	}
	return iAcc;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iN, iM;
		cin >> iN >> iM;
		if (iN == 0) break;
		cout << iN << " " << iM << " ";
		map<int, int> mapA;
		int iIndex = 1;
		mapA.insert({ iN,1 });
		while (true)
		{
			int iNext = CalcDigitPow(iN);
			if (mapA.find(iNext) != mapA.end()) break;
			mapA.insert({ iNext, ++iIndex });
			iN = iNext;
		}
		set<int> setB;
		int iCount = 1;
		int iAns = 1000000000;
		while (true)
		{
			if (mapA.find(iM) != mapA.end())
			{
				iAns = min(iAns, mapA[iM] + iCount);
			}
			if (setB.find(iM) != setB.end())
			{
				break;
			}
			setB.insert(iM);
			iM = CalcDigitPow(iM);
			++iCount;
		}
		if (iAns == 1000000000)
		{
			cout << "0\n";
		}
		else
		{
			cout << iAns << "\n";
		}
	}
	return 0;
}
