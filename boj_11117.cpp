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
		string strBox;
		cin >> strBox;
		vector<int> vecBox(26, 0);
		for (char ch : strBox)
		{
			++vecBox[ch - 'A'];
		}

		int iN;
		cin >> iN;
		for (int i = 0; i < iN; ++i)
		{
			bool bPossible = true;
			string strCookie;
			cin >> strCookie;
			vector<int> vecCookie(26, 0);
			for (char ch : strCookie)
			{
				++vecCookie[ch - 'A'];
			}
			for (int i = 0; i < 26; ++i)
			{
				if (vecCookie[i] > vecBox[i])
				{
					bPossible = false;
				}
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
	}

	return 0;
}
