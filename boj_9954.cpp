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

	string strLine;
	while (true)
	{
		getline(cin, strLine);
		if (strLine == "#") break;

		int iLen = strLine.length() - 1;
		int iChange = strLine[iLen] - 'A';
		for (int i = 0;i < iLen;++i)
		{
			if (strLine[i] >= 'a' && strLine[i] <= 'z')
			{
				cout << (char)((strLine[i] - 'a' - iChange + 26) % 26 + 'a');
			}
			else if (strLine[i] >= 'A' && strLine[i] <= 'Z')
			{
				cout << (char)((strLine[i] - 'A' - iChange + 26) % 26 + 'A');
			}
			else
			{
				cout << strLine[i];
			}
		}
		cout << "\n";
	}

	return 0;
}
