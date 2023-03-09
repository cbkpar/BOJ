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

	int iT;
	cin >> iT;
	while (iT--)
	{
		string strWord;
		cin >> strWord;
		if (isPalindrome(strWord))
		{
			cout << "1\n";
		}
		else
		{
			cout << "2\n";
		}
	}
	return 0;
}
