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
	while (getline(cin,strLine))
	{
		int iLen = strLine.length();
		for (int i = 0; i < iLen; ++i)
		{
			if (i + 4 > iLen)
			{
				cout << strLine[i];
			}
			else
			{
				if (strLine[i] == 'i' && strLine[i + 1] == 'i' && strLine[i + 2] == 'i' && strLine[i + 3] == 'n' && strLine[i + 4] == 'g')
				{
					cout << "th";
					i += 4;
				}
				else
				{
					cout << strLine[i];
				}
			}
		}
		cout << "\n";
	}

	return 0;
}
