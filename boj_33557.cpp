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
	while (iT-- > 0)
	{
		long long lA, lB;
		cin >> lA >> lB;

		long long lMultiple = lA * lB;
		stack<long long> stNum;
		while (lA != 0 || lB != 0)
		{
			if (lA == 0)
			{
				stNum.push(lB % 10);
			}
			else if (lB == 0)
			{
				stNum.push(lA % 10);
			}
			else
			{
				stNum.push((lA % 10) * (lB % 10));
			}
			lA /= 10;
			lB /= 10;
		}
		long long lTotal = 0;
		while (!stNum.empty())
		{
			long long lTemp = stNum.top();
			stNum.pop();
			if (lTemp >= 10)
			{
				lTotal *= 100;
				lTotal += lTemp;
			}
			else
			{
				lTotal *= 10;
				lTotal += lTemp;
			}
		}

		if (lMultiple == lTotal)
		{
			cout << "1" << "\n";
		}
		else
		{
			cout << "0" << "\n";
		}
	}


	return 0;
}
