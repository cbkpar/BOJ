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

	vector<int> vecHeight(iN + 1, 0);
	for (int i = 1;i <= iN;++i)
	{
		cin >> vecHeight[i];
	}

	vector<int> vecCount(iN + 1, 0);
	vector<pair<int, int>> vecNearCity(iN + 1, { 0,0 });


	stack<pair<int, int>> stLeft;
	for (int i = 1;i <= iN;++i)
	{
		while (!stLeft.empty())
		{
			if (stLeft.top().first > vecHeight[i])
			{
				break;
			}
			stLeft.pop();
		}

		if (!stLeft.empty())
		{
			vecNearCity[i].first += stLeft.size();
			vecNearCity[i].second = stLeft.top().second;
		}
		stLeft.push({ vecHeight[i],i });
	}

	stack<pair<int, int>> stRight;
	for (int i = iN;i >= 1;--i)
	{
		while (!stRight.empty())
		{
			if (stRight.top().first > vecHeight[i])
			{
				break;
			}
			stRight.pop();
		}

		if (!stRight.empty())
		{
			vecNearCity[i].first += stRight.size();

			if (vecNearCity[i].second == 0)
			{
				vecNearCity[i].second = stRight.top().second;
			}
			else
			{
				int iLeftDist = i - vecNearCity[i].second;
				int iRightDist = stRight.top().second - i;
				if (iRightDist < iLeftDist)
				{
					vecNearCity[i].second = stRight.top().second;
				}
			}
		}
		stRight.push({ vecHeight[i],i });
	}

	for (int i = 1;i <= iN;++i)
	{
		if (vecNearCity[i].first == 0)
		{
			cout << "0" << "\n";
		}
		else
		{
			cout << vecNearCity[i].first << " " << vecNearCity[i].second << "\n";
		}
	}

	return 0;
}
