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
	int iAns = 0;

	for (int i = 0;i < iLen - 3;++i)
	{
		if (strWord[i] == 'k' && strWord[i + 1] == 'i' && strWord[i + 2] == 'c' && strWord[i + 3] == 'k')
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
