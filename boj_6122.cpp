#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int iN, iQ;
	cin >> iN >> iQ;

	vector<int> vecNum(iN + 1, 0);
	vector<int> vecTime(iN + 1, 0);

	for (int i = 0;i < iQ; ++i)
	{
		int iNum, iH, iM;
		string strType;
		cin >> iNum >> strType >> iH >> iM;

		if (strType == "START")
		{
			vecTime[iNum] = iH * 60 + iM;
		}
		else
		{
			vecNum[iNum] += iH * 60 + iM - vecTime[iNum];
		}
	}

	for (int i = 1;i <= iN;++i)
	{
		cout << (vecNum[i] / 60) << " " << (vecNum[i] % 60) << "\n";
	}

	return 0;
}
