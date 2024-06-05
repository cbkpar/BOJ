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
	for (int t = 1;t <= iT;++t)
	{
		int iN;
		cin >> iN;

		if (iN == 1)
		{
			unsigned long long lP;
			cin >> lP;

			unsigned long long lA = 0;
			unsigned long long lB = 1;

			stack<int> stNum;
			while (lP > 0)
			{
				stNum.push(lP % 2);
				lP /= 2;
			}

			while (!stNum.empty())
			{
				int iDir = stNum.top();
				stNum.pop();
				if (iDir == 0)
				{
					lB += lA;
				}
				else
				{
					lA += lB;
				}
			}
			cout << "Case #" << t << ": ";
			cout << lA << " " << lB << "\n";

		}
		else
		{
			unsigned long long lP, lQ;
			cin >> lP >> lQ;

			stack<int> stNum;
			while (lP != 1 || lQ != 1)
			{
				if (lP > lQ)
				{
					stNum.push(1);
					lP -= lQ;
				}
				else
				{
					stNum.push(0);
					lQ -= lP;
				}
			}

			unsigned long long lNum = 1;
			while (!stNum.empty())
			{
				int iDir = stNum.top();
				stNum.pop();
				if (iDir == 0)
				{
					lNum *= 2;
				}
				else
				{
					lNum *= 2;
					lNum += 1;
				}
			}
			cout << "Case #" << t << ": ";
			cout << lNum << "\n";
		}
	}

	return 0;
}
