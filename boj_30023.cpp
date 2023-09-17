#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

char NextLight(const char& ch)
{
	if (ch == 'R') return 'G';
	if (ch == 'G') return 'B';
	if (ch == 'B') return 'R';
	return ' ';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iCountR = 0;
	int iCountG = 0;
	int iCountB = 0;

	string strLight;
	cin >> strLight;

	string strRed, strGreen, strBlue;
	strRed = strGreen = strBlue = strLight;

	for (int i = 0; i < iN - 2; ++i)
	{
		while (strRed[i] != 'R')
		{
			++iCountR;
			for (int j = i; j < i + 3; ++j)
			{
				strRed[j] = NextLight(strRed[j]);
			}
		}
	}
	if (strRed[iN - 1] != 'R' || strRed[iN - 2] != 'R' || strRed[iN - 3] != 'R')
	{
		iCountR = 1000000000;
	}

	for (int i = 0; i < iN - 2; ++i)
	{
		while (strGreen[i] != 'G')
		{
			++iCountG;
			for (int j = i; j < i + 3; ++j)
			{
				strGreen[j] = NextLight(strGreen[j]);
			}
		}
	}
	if (strGreen[iN - 1] != 'G' || strGreen[iN - 2] != 'G' || strGreen[iN - 3] != 'G')
	{
		iCountG = 1000000000;
	}

	for (int i = 0; i < iN - 2; ++i)
	{
		while (strBlue[i] != 'B')
		{
			++iCountB;
			for (int j = i; j < i + 3; ++j)
			{
				strBlue[j] = NextLight(strBlue[j]);
			}
		}
	}
	if (strBlue[iN - 1] != 'B' || strBlue[iN - 2] != 'B' || strBlue[iN - 3] != 'B')
	{
		iCountB = 1000000000;
	}

	int iAns = min(iCountR, min(iCountG, iCountB));

	if (iAns == 1000000000)
	{
		cout << "-1" << "\n";
	}
	else
	{
		cout << iAns << "\n";
	}
	return 0;
}
