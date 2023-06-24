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

	string strWord;
	cin >> strWord;

	int iLen = strWord.length();

	vector<int> vecPos(iLen, 0);
	for (int i = 0; i < iLen; ++i) vecPos[i] = i;

	vector<int> vecNext(iLen, 0);
	for (int i = 0; i < iLen; ++i)
	{
		if (i < (iLen + 1) / 2)
		{
			vecNext[i * 2] = i;
		}
		else
		{
			vecNext[1 + (iLen - 1 - i) * 2] = i;
		}
	}

	while (iN)
	{
		if (iN & 1)
		{
			vector<int> vecTemp(iLen, 0);
			for (int i = 0; i < iLen; ++i)
			{
				vecTemp[i] = vecNext[vecPos[i]];
			}
			for (int i = 0; i < iLen; ++i)
			{
				vecPos[i] = vecTemp[i];
			}
		}
		vector<int> vecTemp(iLen, 0);
		for (int i = 0; i < iLen; ++i)
		{
			vecTemp[i] = vecNext[vecNext[i]];
		}
		for (int i = 0; i < iLen; ++i)
		{
			vecNext[i] = vecTemp[i];
		}
		iN /= 2;
	}
	string strAns = "";
	strAns.resize(iLen);
	for (int i = 0; i < iLen; ++i)
	{
		strAns[vecPos[i]] = strWord[i];
	}
	cout << strAns << "\n";
	return 0;
}
