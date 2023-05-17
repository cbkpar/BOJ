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
	while (iN--)
	{
		string strWord;
		cin >> strWord;

		int iLen = strWord.length();
		int iSize = 1;
		while (iSize * iSize < iLen)
		{
			++iSize;
		}
		vector<vector<char>> matWord(iSize, vector<char>(iSize, ' '));
		for (int i = 0; i < iLen; ++i)
		{
			matWord[i / iSize][i % iSize] = strWord[i];
		}
		string strAns;
		strAns.resize(iLen);
		int iIndex = 0;
		for (int i = 0; i < iSize; ++i)
		{
			for (int j = iSize - 1; j >= 0; --j)
			{
				if (matWord[j][i] == ' ') continue;
				strAns[iIndex++] = matWord[j][i];
			}
		}
		cout << strAns << "\n";
	}
	return 0;
}
