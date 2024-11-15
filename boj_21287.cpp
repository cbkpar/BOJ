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

	int iN;
	cin >> iN;

	string strWord;
	cin >> strWord;

	string strAns = "";
	for (int i = 0; i < iN; ++i)
	{
		strAns += "R";
	}

	bool bB = false;
	bool bG = false;
	bool bR = false;

	int iIndex = 0;
	for (char ch : strWord)
	{
		if (ch == 'B') bB = true;
		if (ch == 'G') bG = true;
		if (ch == 'R') bR = true;

		if (bB && bG && bR)
		{
			bB = false;
			bG = false;
			bR = false;
			strAns[iIndex++] = ch;
		}
	}

	cout << strAns << "\n";
	return 0;
}
