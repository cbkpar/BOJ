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
	int iSize = strWord.length();

	vector<string> vecAns;
	string strNewWord;
	strNewWord.resize(iSize);
	for (int i = 1; i < iSize; ++i)
	{
		for (int j = i + 1; j < iSize; ++j)
		{
			int iIndex = 0;
			for (int k = i - 1; k >= 0; --k) strNewWord[iIndex++] = strWord[k];
			for (int k = j - 1; k >= i; --k) strNewWord[iIndex++] = strWord[k];
			for (int k = iSize - 1; k >= j; --k) strNewWord[iIndex++] = strWord[k];
			vecAns.push_back(strNewWord);
		}
	}

	sort(vecAns.begin(), vecAns.end());
	cout << vecAns[0] << "\n";

	return 0;
}
