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
	stack<long long> stackWeight;
	stackWeight.push(20);
	long long lAns = 0;
	long long lCount = 0;
	long long lNow = 20;
	for (int i = 0; i < iN; ++i)
	{
		long long lWeight;
		cin >> lWeight;

		if (stackWeight.top() < lWeight)
		{
			stackWeight.push(lWeight);
			lNow = lWeight;
		}
		else
		{
			while (!stackWeight.empty() && stackWeight.top() >= lWeight)
			{
				long long lDiff = lNow - stackWeight.top();
				lAns += lDiff;
				lCount += (lDiff + 30) / 40;
				lNow = stackWeight.top();
				stackWeight.pop();
			}
			stackWeight.push(lWeight);
			if (lNow != stackWeight.top())
			{
				long long lDiff = lNow - stackWeight.top();
				lAns += lDiff;
				lCount += (lDiff + 30) / 40;
				lNow = stackWeight.top();
			}
		}
	}
	while (!stackWeight.empty())
	{
		long long lDiff = lNow - stackWeight.top();
		lAns += lDiff;
		lCount += (lDiff + 30) / 40;
		lNow = stackWeight.top();
		stackWeight.pop();
	}
	cout << (lAns * 2) << " " << (lCount * 4) << "\n";
	return 0;
}
