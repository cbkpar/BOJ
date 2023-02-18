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

	string strCode;
	cin >> strCode;
	int iSizeCode = strCode.length();

	int iT;
	cin >> iT;
	while (iT--)
	{
		string strWord;
		cin >> strWord;
		int iSizeWord = strWord.length();

		string newWord;
		newWord.resize(iSizeCode);

		for (int i = 0; i < 26; ++i)
		{
			for (int j = 0; j < iSizeCode; ++j)
			{
				newWord[j] = (char)((strCode[j] - 'a' + i) % 26 + 'a');
			}
			for (int j = 0; j <= iSizeCode - iSizeWord; ++j)
			{
				for (int k = 0; k < iSizeWord; ++k)
				{
					if (newWord[j + k] != strWord[k]) break;
					if (k == iSizeWord - 1) {
						cout << newWord << "\n";
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
