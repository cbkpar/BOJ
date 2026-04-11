#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	string strLine;
	cin >> strLine;

	int iLen = strLine.length();
	for (int i = 0;i < iLen;++i)
	{
		if (i < iLen - 2)
		{
			if (strLine[i] != strLine[i + 1] &&
				strLine[i + 1] != strLine[i + 2] &&
				strLine[i + 2] != strLine[i])
			{
				cout << "C";
				i += 2;
				continue;
			}
		}
		if (strLine[i] == 'R') cout << "S";
		if (strLine[i] == 'B') cout << "K";
		if (strLine[i] == 'L') cout << "H";
	}
	cout << "\n";

	return 0;
}
