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

	vector<int> vecCount(26, 0);
	int iMid = iN / 2;
	for (int i = 0; i < iMid; ++i)
	{
		vecCount[strWord[i] - 'a']++;
	}
	for (int i = iN - 1; i > iN - iMid - 1; --i)
	{
		vecCount[strWord[i] - 'a']++;
	}

	bool bPossible = true;
	for (int i = 0; i < 26; ++i)
	{
		if (vecCount[i] == 0)
		{
			continue;
		}

		if (vecCount[i] % 2 != 0)
		{
			bPossible = false;
		}
	}

	if (bPossible)
	{
		cout << "Yes" << "\n";
	}
	else
	{
		cout << "No" << "\n";
	}
	return 0;
}
