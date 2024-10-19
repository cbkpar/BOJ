#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lX, lY;
	cin >> lX >> lY;

	queue<pair<long long, long long>> qNum;
	qNum.push({ lX, lY });

	long long lPow = 1;

	while (!qNum.empty())
	{
		int iSize = qNum.size();
		while (iSize-- > 0)
		{
			pair<long long, long long> pNum = qNum.front();
			qNum.pop();
			if (pNum.first == 0 && pNum.second == 0)
			{
				cout << "1" << "\n";
				return 0;
			}

			if (pNum.first >= lPow)
			{
				qNum.push({ pNum.first - lPow, pNum.second });
			}

			if (pNum.second >= lPow)
			{
				qNum.push({ pNum.first, pNum.second - lPow });
			}
		}
		lPow *= 3;
	}

	cout << "0" << "\n";
	return 0;
}
