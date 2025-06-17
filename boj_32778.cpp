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
	getline(cin, strLine);

	int iPos = -1;
	int iLen = strLine.length();
	for (int i = 0;i < iLen;++i)
	{
		if (strLine[i] == '(')
		{
			iPos = i;

		}
	}

	if (iPos == -1)
	{
		cout << strLine << "\n";
		cout << "-" << "\n";
	}
	else
	{
		for (int i = 0;i < iPos - 1;++i)
		{
			cout << strLine[i];
		}
		cout << "\n";

		for (int i = iPos + 1;i < iLen - 1;++i)
		{
			cout << strLine[i];
		}
		cout << "\n";
	}

	return 0;
}
