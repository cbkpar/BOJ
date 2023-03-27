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

	vector<int> vecCount(26, 0);

	string strCode;
	getline(cin, strCode);

	for (char ch : strCode)
	{
		if (ch >= 'a' && ch <= 'z') ++vecCount[(ch - 'a')];
		if (ch >= 'A' && ch <= 'Z') ++vecCount[(ch - 'A')];
	}

	for (int i = 0; i < 26; ++i)
	{
		cout << (char)('A' + i) << " | ";
		while (vecCount[i]--) cout << "*";
		cout << "\n";
	}

	return 0;
}
