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
		long long lPay;
		cin >> lPay;
		if (stackNum.empty() || stackNum.top().first <= lPay)
		{
			stackNum.push({ lPay, i });
		}
		else
		{
			int iTempIndex = i;
			while (!stackNum.empty() && stackNum.top().first > lPay)
			{
				long long lSum = stackNum.top().first * (i - stackNum.top().second);
				lAns = max(lAns, lSum);
				iTempIndex = stackNum.top().second;
				stackNum.pop();
			}
			stackNum.push({ lPay, iTempIndex });
		}
	}
	while (!stackNum.empty())
	{
		long long lSum = stackNum.top().first * (iN - stackNum.top().second);
		lAns = max(lAns, lSum);
		stackNum.pop();
	}
	cout << lAns << "\n";
	return 0;
}
