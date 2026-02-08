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

	int iT;
	cin >> iT;
	for (int t = 0; t < iT; ++t)
	{
		string strA, strB;
		cin >> strA >> strB;

		vector<int> vecCountA(26, 0);
		for (char ch : strA) vecCountA[ch - 'a']++;

		vector<int> vecCountB(26, 0);
		for (char ch : strB) vecCountB[ch - 'a']++;

		bool bPossible = true;
		for (int i = 0; i < 26; ++i)
		{
			if (vecCountB[i] > 0 && vecCountA[i] == 0) bPossible = false;
		}

		if (bPossible)
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
	}


	return 0;
}
