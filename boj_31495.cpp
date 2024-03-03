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

	bool bPossible = true;
	int iLen = strLine.length();

	if (iLen <= 2)
	{
		bPossible = false;
	}
	else
	{
		if (strLine[0] != '"' || strLine[iLen - 1] != '"')
		{
			bPossible = false;
		}
	}

	if (bPossible)
	{
		for (int i = 1; i < iLen - 1; ++i)
		{
			cout << strLine[i];
		}
		cout << "\n";
	}
	else
	{
		cout << "CE" << "\n";
	}
	return 0;
}
