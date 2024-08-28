#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> vecNum(501, vector<int>());
	vecNum[0].push_back(1);
	for (int i = 1;i <= 500;++i)
	{
		int iSize = vecNum[i - 1].size();
		int iTemp = 0;
		stack<int> stTemp;
		for (int j = iSize - 1;j >= 0;--j)
		{
			iTemp += vecNum[i - 1][j] * i;
			stTemp.push(iTemp % 10);
			iTemp /= 10;
		}
		while (iTemp > 0)
		{
			stTemp.push(iTemp % 10);
			iTemp /= 10;
		}
		while (!stTemp.empty())
		{
			vecNum[i].push_back(stTemp.top());
			stTemp.pop();
		}
	}

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN, iDigit;
		cin >> iN >> iDigit;

		int iAns = 0;
		for (int iNum : vecNum[iN])
		{
			if (iNum == iDigit)
			{
				++iAns;
			}
		}
		cout << iAns << "\n";
	}
	return 0;
}
