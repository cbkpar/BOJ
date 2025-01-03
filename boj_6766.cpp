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

	int iK;
	cin >> iK;

	string strWord;
	cin >> strWord;

	int iLen = strWord.length();
	for (int i = 0; i < iLen; ++i)
	{
		int iOrder = strWord[i] - 'A';
		iOrder = (iOrder - 3 * (i + 1) - iK + 2600) % 26;
		cout << (char)(iOrder + 'A');
	}
	cout << "\n";
	return 0;
}
