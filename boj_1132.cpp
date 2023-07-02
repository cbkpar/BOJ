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

	vector<pair<long long, long long>> vecNum(10, { 0,0 });
	for (int i = 0; i < iN; ++i)
	{
		string strWord;
		cin >> strWord;

		int iSize = strWord.length();
		long long lTemp = 1;
		for (int j = iSize - 1; j >= 0; --j)
		{
			vecNum[strWord[j] - 'A'].first += lTemp;
			lTemp *= 10;
		}
		vecNum[strWord[0] - 'A'].second = 1;
	}
	
	long long lAns = 0;
	long long lNow = 1;
	sort(vecNum.begin(), vecNum.end());
	vector<bool> vecUsed(10, false);
	for (long long i = 0; i < 10; ++i)
	{
		if (vecNum[i].second == 0)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (i == j) continue;
				lAns += vecNum[j].first * lNow;
				++lNow;
			}
			break;
		}
	}
	cout << lAns << "\n";
	return 0;
}
