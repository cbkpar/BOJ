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

	while (true)
	{
		string strLine;
		cin >> strLine;

		if (strLine == "0+0=0")
		{
			cout << "True" << "\n";
			break;
		}

		int iC = 0;
		int iB = 0;
		int iA = 0;
		
		int iLen = strLine.length();
		int iNow = iLen - 1;
		while (true)
		{
			iC *= 10;
			iC += strLine[iNow] - '0';
			if (strLine[--iNow] == '=') break;
		}
		--iNow;
		while (true)
		{
			iB *= 10;
			iB += strLine[iNow] - '0';
			if (strLine[--iNow] == '+') break;
		}
		--iNow;
		while (true)
		{
			iA *= 10;
			iA += strLine[iNow] - '0';
			if (--iNow == -1) break;
		}

		cout << (iA + iB == iC ? "True" : "False") << "\n";
	}

	return 0;
}
