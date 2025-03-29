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

	for (int t = 0; t < iT; ++t)
	{
		long long lN;
		cin >> lN;

		stack<int> stNum;

		while (lN > 1)
		{
			if (lN % 2 == 0)
			{
				stNum.push(0);
			}
			else
			{
				stNum.push(1);
			}
			lN /= 2;
		}

		long long lTemp = 1;
		long long lTemp2 = 1;
		stack<long long> stAns1;
		stack<long long> stAns2;
		stAns1.push(lTemp);
		stAns2.push(lTemp2);
		while (!stNum.empty())
		{
			lTemp += 1;
			lTemp2 *= 2;
			if (stNum.top() == 0)
			{
				lTemp2 -= 1;
			}
			stNum.pop();
			stAns1.push(lTemp);
			stAns2.push(lTemp2);
		}
		while (!stAns1.empty())
		{
			printf("%lld", stAns1.top());
			printf("%018lld\n", stAns2.top());

			stAns1.pop();
			stAns2.pop();
		}

	}
	return 0;
}
