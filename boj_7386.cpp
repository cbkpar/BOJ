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

	vector<int> vecCountA(26, 0);
	vector<int> vecCountB(26, 0);

	string strBefore, strAfter;
	cin >> strBefore >> strAfter;

	for (char ch : strBefore)
	{
		++vecCountA[ch - 'A'];
	}
	for (char ch : strAfter)
	{
		++vecCountB[ch - 'A'];
	}
	sort(vecCountA.begin(), vecCountA.end());
	sort(vecCountB.begin(), vecCountB.end());

	bool bPossible = true;
	for (int i = 0; i < 26; ++i)
	{
		if (vecCountA[i] != vecCountB[i])
		{
			bPossible = false;
		}
	}

	cout << (bPossible ? "YES" : "NO") << "\n";
	return 0;
}
