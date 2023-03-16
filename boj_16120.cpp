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

	string strWord;
	cin >> strWord;

	int iSize = strWord.length();
	vector<int> vecNum(iSize, 0);
	int iNow = 0;

	for (int i = 0; i < iSize; ++i)
	{
		if (strWord[i] == 'P')
		{
			vecNum[iNow++] = 1;
		}
		else
		{
			vecNum[iNow++] = 2;
		}
		while (iNow >= 4 && vecNum[iNow - 1] == 1 && vecNum[iNow - 2] == 2 && vecNum[iNow - 3] == 1 && vecNum[iNow - 4] == 1)
		{
			iNow -= 3;
		}
	}

	if (iNow == 1 && vecNum[0] == 1)
	{
		cout << "PPAP\n";
	}
	else
	{
		cout << "NP\n";
	}

	return 0;
}
