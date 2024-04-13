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

	int iLen;
	cin >> iLen;

	string strWord;
	cin >> strWord;

	for (int i = 1;i < iLen;++i)
	{
		if (strWord[i] == strWord[i - 1])
		{
			strWord[i] = strWord[i] - 'a' + 'A';
			strWord[i-1] = strWord[i-1] - 'a' + 'A';
		}
	}

	cout << strWord << "\n";
	return 0;
}
