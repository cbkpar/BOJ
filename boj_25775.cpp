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

	int iMaxSize = 0;

	vector<vector<int>> matCount(31, vector<int>(26, 0));
	for (int i = 0; i < iN; ++i)
	{
		string strWord;
		cin >> strWord;

		int iSize = strWord.length();
		iMaxSize = max(iMaxSize, iSize);
		for (int j = 1; j <= iSize; ++j)
		{
			++matCount[j][strWord[j - 1] - 'a'];
		}
	}
	for (int i = 1; i <= iMaxSize; ++i)
	{
		cout << i << ":";
		int iMaxCount = 1;
		for (int j = 0; j < 26; ++j)
		{
			iMaxCount = max(iMaxCount, matCount[i][j]);
		}
		for (int j = 0; j < 26; ++j)
		{
			if (matCount[i][j] == iMaxCount)
			{
				cout << " " << (char)(j + 'a');
			}
		}
		cout << "\n";
	}
	return 0;
}
