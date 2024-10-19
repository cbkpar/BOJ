#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string strIndex = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iN;
		cin >> iN;

		if (iN == 0) break;

		string strWord;
		cin >> strWord;
		int iLen = strWord.length();

		for (int i = iLen - 1; i >= 0; --i)
		{
			int iIndex = 0;
			if (strWord[i] >= 'A' && strWord[i] <= 'Z')
			{
				iIndex = strWord[i] - 'A';
			}
			else if (strWord[i] == '_')
			{
				iIndex = 26;
			}
			else if (strWord[i] == '.')
			{
				iIndex = 27;
			}
			iIndex = (iIndex + iN) % 28;
			
			if (iIndex < 26)
			{
				cout << (char)(iIndex + 'A');
			}
			else if (iIndex == 26)
			{
				cout << "_";
			}
			else
			{
				cout << ".";
			}
		}
		cout << "\n";
	}
	return 0;
}
