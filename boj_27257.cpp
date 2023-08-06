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

	int iAns = 0;

	int iLen = strWord.length();
	for (int i = 0; i < iLen; ++i)
	{
		if (strWord[i] == '0')
		{
			++iAns;
		}
	}
	for (int i = iLen - 1; i >= 0; --i)
	{
		if (strWord[i] != '0') break;
		--iAns;
	}

	cout << iAns << "\n";
	return 0;
}
