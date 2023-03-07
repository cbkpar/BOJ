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

	string strA, strB;
	cin >> strA >> strB;

	int iSizeA = strA.length();
	int iSizeB = strB.length();
	int iSize = max(iSizeA, iSizeB);
	vector<int> vecAns(iSize, 0);
	for (int i = 0; i < iSizeA; ++i) vecAns[i] += strA[iSizeA - 1 - i] - '0';
	for (int i = 0; i < iSizeB; ++i) vecAns[i] += strB[iSizeB - 1 - i] - '0';
	for (int i = 0; i < iSize; ++i)
	{
		if (vecAns[i] >= 10)
		{
			if (i == iSize - 1) vecAns.push_back(0);
			vecAns[i + 1] += vecAns[i] / 10;
			vecAns[i] %= 10;
		}
	}
	for (int i = vecAns.size() - 1; i >= 0; --i)
	{
		cout << vecAns[i];
	}
	cout << "\n";
	return 0;
}
