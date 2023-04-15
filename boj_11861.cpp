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
	stack<pair<long long, long long>> stackNum;
	long long lAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		long long lNum;
		cin >> lNum;

		if (stackNum.empty() || stackNum.top().first <= lNum)
		{
			stackNum.push({ lNum,i });
		}
		else
		{
			int iTempIndex = i;
			while (!stackNum.empty() && stackNum.top().first > lNum)
			{
				long long lArea = stackNum.top().first * (i - stackNum.top().second);
				lAns = max(lAns, lArea);
				iTempIndex = stackNum.top().second;
				stackNum.pop();
			}
			stackNum.push({ lNum, iTempIndex });
		}
	}
	while (!stackNum.empty())
	{
		long long lArea = stackNum.top().first * (iN - stackNum.top().second);
		lAns = max(lAns, lArea);
		stackNum.pop();
	}
	cout << lAns << "\n";
	return 0;
}
