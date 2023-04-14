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

	int iN;
	cin >> iN;

	vector<long long> vecNum(iN + 1, 0);
	vector<long long> presum(iN + 1, 0);
	for (int i = 1; i <= iN; ++i) cin >> vecNum[i];
	for (int i = 1; i <= iN; ++i) presum[i] = presum[i - 1] + vecNum[i];

	stack<pair<long long, long long>> stackNum;

	long long lAns = -1;
	int iS = 0;
	int iE = 0;

	for (int i = 1; i <= iN; ++i)
	{
		if (stackNum.empty() || stackNum.top().first <= vecNum[i])
		{
			stackNum.push({ vecNum[i],i });
		}
		else
		{
			int iTempIndex = i;
			while (!stackNum.empty() && stackNum.top().first > vecNum[i])
			{
				long long lTempSum = stackNum.top().first * (presum[i - 1] - presum[stackNum.top().second - 1]);
				if (lAns < lTempSum)
				{
					lAns = lTempSum;
					iS = stackNum.top().second;
					iE = i - 1;
				}
				iTempIndex = stackNum.top().second;
				stackNum.pop();
			}
			stackNum.push({ vecNum[i], iTempIndex });
		}
	}
	while (!stackNum.empty())
	{
		long long lTempSum = stackNum.top().first * (presum[iN] - presum[stackNum.top().second - 1]);
		if (lAns < lTempSum)
		{
			lAns = lTempSum;
			iS = stackNum.top().second;
			iE = iN;
		}
		stackNum.pop();
	}

	cout << lAns << "\n";
	cout << iS << " " << iE << "\n";
	return 0;
}
