#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;
	vector<string> vecLeft(iN, "");
	vector<string> vecRight(iN, "");

	for (int i = 0; i < iN; ++i)
	{
		string strWord;
		cin >> strWord;

		vecLeft[i].resize(iK);
		vecRight[i].resize(iK);
		for (int j = 0; j < iK; ++j)
		{
			vecLeft[i][j] = strWord[j];
			vecRight[i][j] = strWord[2 * iK - 1 - j];
		}
	}
	sort(vecLeft.begin(), vecLeft.end());
	sort(vecRight.begin(), vecRight.end());

	int iAns = iN * 2 * iK;
	for (int i = 1; i < iN; ++i)
	{
		for (int j = 0; j < iK; ++j)
		{
			if (vecLeft[i - 1][j] != vecLeft[i][j])
			{
				break;
			}
			--iAns;
		}
		for (int j = 0; j < iK; ++j)
		{
			if (vecRight[i - 1][j] != vecRight[i][j])
			{
				break;
			}
			--iAns;
		}
	}
	cout << iAns << "\n";
	return 0;
}
