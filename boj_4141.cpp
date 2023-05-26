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

char ArrCh[26] = { '2' ,'2' ,'2' ,'3','3','3','4','4','4','5' ,'5' ,'5' ,'6' ,'6' ,'6'
,'7' ,'7' ,'7','7','8','8','8','9','9','9','9' };

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

		string strAns = "";

		for (char ch : strWord)
		{
			if (ch >= 'a' && ch <= 'z') strAns += ArrCh[ch - 'a'];
			if (ch >= 'A' && ch <= 'Z') strAns += ArrCh[ch - 'A'];
		}
		cout << (isPalindrome(strAns) ? "YES" : "NO") << "\n";
	}
	return 0;
}
