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

	while (cin >> strWord)
	{
		int iLen = strWord.length();
		for (int i = 0;i < iLen;i += 2)
		{
			char chA = strWord[i];
			char chB = strWord[i + 1];

			int iA = (chA >= '0' && chA <= '9') ? chA - '0' : chA - 'A' + 10;
			int iB = (chB >= '0' && chB <= '9') ? chB - '0' : chB - 'A' + 10;
			cout << (char)(iA * 16 + iB);
		}
		cout << "\n";

	}

	return 0;
}
