#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	string strWord;
	cin >> strWord;

	bool bPalindrome = true;
	int iLen = strWord.length();
	for (int i = 0;i < iLen;++i)
	{
		if (strWord[i] != strWord[iLen - 1 - i])
		{
			bPalindrome = false;
		}
	}

	cout << (bPalindrome ? "beep" : "boop") << "\n";
	return 0;
}
