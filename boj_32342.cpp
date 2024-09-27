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

	for (int i = 0;i < iN;++i)
	{
		string strWord;
		cin >> strWord;

		int iAns = 0;
		int iLen = strWord.length();
		for (int j = 2;j < iLen;++j)
		{
			if (strWord[j - 2] == 'W' && strWord[j - 1] == 'O' && strWord[j] == 'W')
			{
				++iAns;
			}
		}
		cout << iAns << "\n";
	}
	return 0;
}
