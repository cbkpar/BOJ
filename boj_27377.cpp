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

	int iT;
	cin >> iT;
	while (iT--)
	{
		long long lN, lS, lT;
		cin >> lN >> lS >> lT;

		long long lCost = lS;
		long long lCount = 1;
		stack<long long> stackNum;
		while (lN)
		{
			stackNum.push(lN % 2);
			lN /= 2;
		}
		stackNum.pop();
		while (!stackNum.empty())
		{
			long long lNum = stackNum.top();
			stackNum.pop();
			long long lTempCount = lCount;
			if (lTempCount <= lT / lS)
			{
				lCost += lTempCount * lS;
			}
			else
			{
				lCost += lT;
			}
			if (lNum == 1)
			{
				lCost += lS;
				lCount += 1;
			}
			lCount += lTempCount;
		}
		cout << lCost << "\n";
	}

	return 0;
}
