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

	int iK;
	cin >> iK;

	if (iK % 2 == 0)
	{
		cout << "YES" << "\n";
		return 0;
	}

	int iLen = strWord.length();
	for (int i = 0; i < iLen; ++i)
	{
		if (strWord[i] != strWord[iLen - i - 1])
		{
			cout << "NO" << "\n";
			return 0;

		}
	}

	cout << "YES" << "\n";
	return 0;
}
