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

	while (iN-- > 0)
	{
		string strWord;
		cin >> strWord;
		int iLen = strWord.length();

		vector<vector<char>> matAns(iLen, vector<char>(iLen, ' '));
		for (int i = 0;i < iLen;++i)
		{
			matAns[0][i] = strWord[i];
			matAns[i][0] = strWord[i];
		}
		for (int i = 0;i < iLen;++i)
		{
			matAns[iLen-1][iLen-1-i] = strWord[i];
			matAns[iLen-1-i][iLen-1] = strWord[i];
		}
		for (int i = 0;i < iLen;++i)
		{
			for (int j = 0;j < iLen;++j)
			{
				cout << matAns[i][j];
			}
			cout << "\n";
		}

	}

	return 0;
}
