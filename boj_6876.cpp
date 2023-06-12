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

	int iT;
	cin >> iT;
	while (iT--)
	{
		string strCode;
		cin >> strCode;
		int iIndex = 0;
		vector<int> vecAns(10, 0);
		for (char ch : strCode)
		{
			if (iIndex == 10) break;
			if (ch >= '0' && ch <= '9')
			{
				vecAns[iIndex++] = ch - '0';
			}
			if (ch >= 'A' && ch <= 'Z')
			{
				if (ch >= 'A' && ch <= 'C') vecAns[iIndex++] = 2;
				if (ch >= 'D' && ch <= 'F') vecAns[iIndex++] = 3;
				if (ch >= 'G' && ch <= 'I') vecAns[iIndex++] = 4;
				if (ch >= 'J' && ch <= 'L') vecAns[iIndex++] = 5;
				if (ch >= 'M' && ch <= 'O') vecAns[iIndex++] = 6;
				if (ch >= 'P' && ch <= 'S') vecAns[iIndex++] = 7;
				if (ch >= 'T' && ch <= 'V') vecAns[iIndex++] = 8;
				if (ch >= 'W' && ch <= 'Z') vecAns[iIndex++] = 9;
			}
		}
		cout << vecAns[0] << vecAns[1] << vecAns[2] << "-";
		cout << vecAns[3] << vecAns[4] << vecAns[5] << "-";
		cout << vecAns[6] << vecAns[7] << vecAns[8] << vecAns[9] << "\n";
	}
	return 0;
}
