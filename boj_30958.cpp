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

	int iN;
	cin >> iN;

	cin.ignore();
	string strWord;
	getline(cin, strWord);

	vector<int> vecCount(26, 0);
	for (char ch : strWord)
	{
		if (ch >= 'a' && ch <= 'z')
		{
			++vecCount[ch - 'a'];
		}
	}

	int iAns = 0;
	for (int i = 0;i < 26;++i)
	{
		iAns = max(iAns, vecCount[i]);
	}

	cout << iAns << "\n";
	return 0;
}
