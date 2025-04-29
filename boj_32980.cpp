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
	vector<long long> vecCount(26, 0);
	for (int i = 0;i < iN;++i)
	{
		string strWord;
		cin >> strWord;

		bool bSame = true;
		int iLen = strWord.length();
		for (int j = 1;j < iLen;++j)
		{
			if (strWord[j] != strWord[j - 1])
			{
				bSame = false;
				break;
			}
		}
		if (bSame)
		{
			vecCount[strWord[0] - 'A'] += iLen;
		}
		else
		{
			vecCount['O' - 'A'] += iLen;
		}
	}

	vector<long long> vecNum(26, 0);
	cin >> vecNum['P' - 'A'];
	cin >> vecNum['C' - 'A'];
	cin >> vecNum['V' - 'A'];
	cin >> vecNum['S' - 'A'];
	cin >> vecNum['G' - 'A'];
	cin >> vecNum['F' - 'A'];
	cin >> vecNum['O' - 'A'];

	for (int i = 0;i < 26;++i)
	{
		if (vecNum[i] > vecNum['O' - 'A'])
		{
			vecNum[i] = vecNum['O' - 'A'];
		}
	}

	long long lAns = 0;
	for (int i = 0;i < 26;++i)
	{
		lAns += vecNum[i] * vecCount[i];
	}

	cout << lAns << "\n";
	return 0;
}
