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

	int iSize = strWord.length();
	for (int i = 1; i < iSize - 1; ++i)
	{
		if (strWord[i - 1] - strWord[i] != strWord[i] - strWord[i + 1])
		{
			cout << "흥칫뿡!! <(￣ ﹌ ￣)>\n";
			return 0;
		}
	}
	cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!\n";
	return 0;
}
