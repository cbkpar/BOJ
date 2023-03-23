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

	vector<int> vecNum(iN);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	int iNum, iSum;
	string strDir;

	cin >> iNum >> strDir;
	iSum = 0;
	if (strDir == "right")
	{
		for (int i = iNum - 1; i < iN; ++i)
		{
			iSum += vecNum[i];
		}
	}
	else
	{
		for (int i = iNum - 1; i >= 0; --i)
		{
			iSum += vecNum[i];
		}
	}
	cout << iSum << " ";

	cin >> iNum >> strDir;
	iSum = 0;
	if (strDir == "right")
	{
		for (int i = iNum - 1; i < iN; ++i)
		{
			if (vecNum[i] == 0) ++iSum;
		}
	}
	else
	{
		for (int i = iNum - 1; i >= 0; --i)
		{
			if (vecNum[i] == 0) ++iSum;
		}
	}
	cout << iSum << "\n";

	return 0;
}
