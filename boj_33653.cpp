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

	string strWord;
	cin >> strWord;
	int iLen = strWord.length();

	int iN;
	cin >> iN;

	int iAns = 0;
	for (int t = 0;t < iN;++t)
	{
		string strTemp;
		cin >> strTemp;
		int iLenTemp = strTemp.length();

		for (int i = 0;i < iLenTemp;++i)
		{
			for (int j = 0;j < iLen;++j)
			{
				if (i + j >= iLenTemp) break;
				if (strTemp[i + j] != strWord[j]) break;
				if (j == iLen - 1) ++iAns;
			}
		}

	}

	cout << iAns << "\n";
	return 0;
}
