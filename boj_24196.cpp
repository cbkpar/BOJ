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

	int iLen = strWord.length();
	int iNow = 0;
	while (iNow < iLen)
	{
		cout << strWord[iNow];
		iNow += (strWord[iNow] - 'A' + 1);
	}
	cout << "\n";
	return 0;
}
