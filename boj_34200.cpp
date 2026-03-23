#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN;
	cin >> iN;
	int iLast = 0;
	vector<int> vecDP(250002, 1000000000);
	vector<bool> vecObstacle(250002, false);

	for (int i = 0;i < iN;++i)
	{
		int iX;
		cin >> iX;
		vecObstacle[iX] = true;
		iLast = max(iLast, iX);
	}

	vecDP[0] = 0;
	for (int i = 1;i <= 250001;++i)
	{
		if (vecObstacle[i])
		{
			continue;
		}
		if (vecObstacle[i - 1])
		{
			vecDP[i] = vecDP[i - 2] + 1;
		}
		else
		{
			if (i >= 2)
			{
				vecDP[i] = min(vecDP[i - 1], vecDP[i - 2]) + 1;
			}
			else
			{
				vecDP[i] = vecDP[i - 1] + 1;
			}
		}
	}

	if (vecDP[iLast + 1] >= 1000000000)
	{
		cout << "-1" << "\n";
	}
	else
	{
		cout << vecDP[iLast + 1] << "\n";
	}
	return 0;
}
