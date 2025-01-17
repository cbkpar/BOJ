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
	while (iT-- > 0)
	{
		string strA, strB;
		cin >> strA >> strB;

		vector<int> vecCount(26, 0);
		for (char ch : strB)
		{
			vecCount[ch - 'a']++;
		}

		int iLeft = 0;
		int iLen = strA.length();
		bool bPossible = false;
		for (int i = 0;i < iLen;++i)
		{
			vecCount[strA[i] - 'a']--;
			while (vecCount[strA[i] - 'a'] < 0)
			{
				vecCount[strA[iLeft++]-'a']++;
			}

			for (int i = 0;i < 26;++i)
			{
				if (vecCount[i] != 0) break;
				if (i == 25) bPossible = true;
			}
		}
		cout << (bPossible ? "YES" : "NO") << "\n";
	}

	return 0;
}
