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

	int iL = 0;
	int iO = 0;
	for (char ch : strWord)
	{
		if (ch == 'L') ++iL;
		if (ch == 'O') ++iO;
	}

	int iAns = -1;
	int iLCount = 0;
	int iOCount = 0;

	for (int i = 0;i < iN - 1;++i)
	{
		if (strWord[i] == 'L') ++iLCount;
		if (strWord[i] == 'O') ++iOCount;

		if (iLCount * 2 != iL && iOCount * 2 != iO)
		{
			iAns = i + 1;
		}
	}

	cout << iAns << "\n";
	return 0;
}
