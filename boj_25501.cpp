#include <iostream>
#include <string.h>

int g_iCount = 0;

int recursion(const char *s, int l, int r) {
	++g_iCount;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char *s) {
	return recursion(s, 0, strlen(s) - 1);
}

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int iTest;
	cin >> iTest;
	char* str = new char[1001];
	while (iTest--)
	{
		cin >> str;
		g_iCount = 0;
		cout << (isPalindrome(str) ? 1 : 0) << " " << g_iCount << "\n";
	}
	delete str;
	return 0;
}
