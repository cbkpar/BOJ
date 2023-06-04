#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isPalindrome(string s) {
	int i = 0, j = s.length() - 1;
	while (i < j) {
		if (s[i] != s[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strWord;
	cin >> strWord;

	int iSize = strWord.length();
	int iAns = 1;

	for (int i = 0; i < iSize; ++i)
	{
		for (int j = i + 1; j <= iSize; ++j)
		{
			if (isPalindrome(strWord.substr(i, j - i)))
			{
				iAns = max(iAns, j - i);
			}
		}
	}
	cout << iAns << "\n";
	return 0;
}
