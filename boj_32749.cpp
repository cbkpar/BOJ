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

	int iN, iT;
	cin >> iN >> iT;

	string strLine;
	cin >> strLine;

	vector<string> vecWord;
	int iLen = 1;
	for (int i = 0;i < (iN - iT);++i)
	{
		iLen *= 2;
	}
	for (int i = 0;i < (1 << iN);i += iLen)
	{
		vecWord.push_back(strLine.substr(i, iLen));
	}
	sort(vecWord.begin(), vecWord.end(), greater<>());

	cout << vecWord[0] << "\n";
	return 0;
}
