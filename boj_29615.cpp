#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<int> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecNum[i];
	}

	vector<bool> vecVisited(iN, false);
	for (int i = 0; i < iM; ++i)
	{
		int iNum;
		cin >> iNum;
		for (int j = 0; j < iN; ++j)
		{
			if (vecNum[j] == iNum)
			{
				vecVisited[j] = true;
			}
		}
	}

	int iAns = 0;
	for (int i = iN - 1; i >= 0; --i)
	{
		if (!vecVisited[i]) continue;
		for (int j = 0; j < i; ++j)
		{
			if (!vecVisited[j])
			{
				vecVisited[j] = true;
				++iAns;
				break;
			}
		}
	}
	
	cout << iAns << "\n";
	return 0;
}
