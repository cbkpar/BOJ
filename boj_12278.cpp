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
			int iP;
			cin >> iP;

			long long lA = 0;
			long long lB = 1;

			stack<int> stNum;
			while (iP > 0)
			{
				stNum.push(iP % 2);
				iP /= 2;
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
			int iP, iQ;
			cin >> iP >> iQ;

			stack<int> stNum;
			while (iP != 1 || iQ != 1)
			{
				if (iP > iQ)
				{
					stNum.push(1);
					iP -= iQ;
				}
				else
				{
					stNum.push(0);
					iQ -= iP;
				}
			}

			long long lNum = 1;
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
