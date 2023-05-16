#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int GetNum(char ch)
{
	if (ch >= 'a' && ch <= 'z') return ch - 'a';
	if (ch >= 'A' && ch <= 'Z') return ch - 'A';
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	while (iN--)
	{
		string strName;
		cin >> strName;
		vector<int> vecCount(26, 0);
		int iSize = strName.length();
		for (int i = 0; i < iSize; ++i)
		{
			int iNum = GetNum(strName[i]);
			if (iNum == -1) continue;
			++vecCount[iNum];
		}
		bool bPossible = true;
		for (int i = 0; i < 13; ++i)
		{
			if (vecCount[i] != vecCount[25 - i])
			{
				bPossible = false;
				break;
			}
		}
		cout << (bPossible ? "Yes\n" : "No\n");
	}
	return 0;
}
