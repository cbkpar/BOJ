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

	for (int i = 1; i < iSize; ++i)
	{
		string strWord1 = strWord.substr(0, i);
		string strWord2 = strWord.substr(i, iSize - i);
		if (isPalindrome(strWord1) && isPalindrome(strWord2))
		{
			cout << strWord1 << " " << strWord2 << "\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
