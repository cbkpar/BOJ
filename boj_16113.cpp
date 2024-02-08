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

	int iLen;
	cin >> iLen;

	string strWord;
	cin >> strWord;

	vector<vector<char>> matWord(5, vector<char>(iLen / 5, ' '));
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < iLen / 5; ++j)
		{
			matWord[i][j] = strWord[i * iLen / 5 + j];
		}
	}

	int iNow = 0;
	int iWordLen = iLen / 5;

	while (iNow < iWordLen)
	{
		int iBit = 0;
		int iIndex = 0;
		for (int i = iNow; i < iNow + 3 && i < iWordLen; ++i)
		{
			bool bBlank = true;
			for (int j = 0; j < 5; ++j)
			{
				if (matWord[j][i] == '#')
				{
					bBlank = false;
					iBit += (1 << iIndex);
				}
				++iIndex;
			}
			++iNow;
			if (bBlank) break;
		}
		if (iBit == 32319) cout << "0";
		if (iBit == 31) cout << "1";
		if (iBit == 24253) cout << "2";
		if (iBit == 32437) cout << "3";
		if (iBit == 31879) cout << "4";
		if (iBit == 30391) cout << "5";
		if (iBit == 30399) cout << "6";
		if (iBit == 31777) cout << "7";
		if (iBit == 32447) cout << "8";
		if (iBit == 32439) cout << "9";
	}
	cout << "\n";
	return 0;
}
