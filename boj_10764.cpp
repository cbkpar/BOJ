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

	int iN, iM;
	cin >> iN >> iM;
	vector<string> vecWord(iN, "");
	for (int i = 0; i < iN; ++i) cin >> vecWord[i];

	int iAns = 0;
	for (char p = 'A'; p <= 'Z'; ++p)
	{
		if (p == 'M') continue;
		for (char q = 'A'; q <= 'Z'; ++q)
		{
			if (q == 'O') continue;
			if (p == q) continue;

			int iCount = 0;
			for (int i = 0; i < iN; ++i)
			{
				for (int j = 0; j < iM; ++j)
				{
					if (i >= 2 && j < iM - 2)
					{
						if (vecWord[i][j] == p && vecWord[i - 1][j + 1] == q && vecWord[i - 2][j + 2] == q) ++iCount;
						if (vecWord[i][j] == q && vecWord[i - 1][j + 1] == q && vecWord[i - 2][j + 2] == p) ++iCount;
					}
					if (j < iM - 2)
					{
						if (vecWord[i][j] == p && vecWord[i][j + 1] == q && vecWord[i][j + 2] == q) ++iCount;
						if (vecWord[i][j] == q && vecWord[i][j + 1] == q && vecWord[i][j + 2] == p) ++iCount;
					}
					if (i < iN - 2 && j < iM - 2)
					{
						if (vecWord[i][j] == p && vecWord[i + 1][j + 1] == q && vecWord[i + 2][j + 2] == q) ++iCount;
						if (vecWord[i][j] == q && vecWord[i + 1][j + 1] == q && vecWord[i + 2][j + 2] == p) ++iCount;
					}
					if (i < iN - 2)
					{
						if (vecWord[i][j] == p && vecWord[i + 1][j] == q && vecWord[i + 2][j] == q) ++iCount;
						if (vecWord[i][j] == q && vecWord[i + 1][j] == q && vecWord[i + 2][j] == p) ++iCount;
					}
				}
			}
			iAns = max(iAns, iCount);
		}

	}
	cout << iAns << "\n";
	return 0;
}
