#include <iostream>
#include <string>

using namespace std;

int matDP[1001][1001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strWord;
	cin >> strWord;

	int iLen = strWord.length();
	for (int i = 0;i < iLen;++i)
	{
		matDP[i][i] = 1;
		matDP[i][i + 1] = (strWord[i] == strWord[i + 1] ? 3 : 2);
	}

	for (int i = 2;i < iLen;++i)
	{
		for (int j = 0;i + j < iLen;++j)
		{
			matDP[j][j + i] = (matDP[j + 1][j + i] + matDP[j][j + i - 1] - matDP[j + 1][j + i - 1] + 10007) % 10007;
			if (strWord[j] == strWord[j + i]) matDP[j][j + i] = (matDP[j][j + i] + matDP[j + 1][j + i - 1] + 1) % 10007;
		}
	}

	cout << matDP[0][iLen - 1] << "\n";

	return 0;
}
