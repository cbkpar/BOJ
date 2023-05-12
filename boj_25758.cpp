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

	vector<vector<bool>> vecExist(26, vector<bool>(2, false));
	vector<bool> vecAns(26, false);

	int iN;
	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		string strGene;
		cin >> strGene;

		int iFront = strGene[0] - 'A';
		int iLast = strGene[1] - 'A';

		for (int i = 0; i < 26; ++i)
		{
			if (vecExist[i][0])
			{
				vecAns[max(iLast, i)] = true;
			}
			if (vecExist[i][1])
			{
				vecAns[max(iFront, i)] = true;
			}
		}
		vecExist[iFront][0] = true;
		vecExist[iLast][1] = true;
	}
	int iCount = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (vecAns[i])
		{
			++iCount;
		}
	}
	cout << iCount << "\n";
	for (int i = 0; i < 26; ++i)
	{
		if (vecAns[i])
		{
			cout << (char)(i + 'A') << (--iCount == 0 ? "\n" : " ");
		}
	}
	return 0;
}
