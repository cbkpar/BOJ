#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<int> vecNum(iN + 1, 0);
	for (int i = 1; i <= iN; ++i)
	{
		cin >> vecNum[i];
	}

	vector<pair<int, int>> vecAns;
	for (int i = 1; i <= iN; ++i)
	{
		for (int j = i; j <= iN; ++j)
		{
			if (vecNum[j] == i && j != i)
			{
				vecAns.push_back({ i,j });
				for (int k = 0; k < (j - i + 1) / 2; ++k)
				{
					swap(vecNum[i + k], vecNum[j - k]);
				}
				break;
			}
		}
	}

	int iSize = vecAns.size();
	cout << iSize << "\n";

	for (int i = 0; i < iSize; ++i)
	{
		cout << vecAns[i].first << " " << vecAns[i].second << "\n";
	}
	return 0;
}
