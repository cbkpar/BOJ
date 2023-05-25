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

	int iN, iK;
	cin >> iN >> iK;

	vector<bool> vecVisited(iN + 1, false);
	vecVisited[0] = true;
	queue<int> qPos;
	qPos.push(0);

	while (!qPos.empty())
	{
		if (iK-- <= 0) break;
		int iSize = qPos.size();
		while (iSize--)
		{
			int iPos = qPos.front();
			qPos.pop();
			if (iPos + 1 <= iN && !vecVisited[iPos + 1])
			{
				vecVisited[iPos + 1] = true;
				qPos.push(iPos + 1);
			}
			if (iPos + iPos/2 <= iN && !vecVisited[iPos + +iPos / 2])
			{
				vecVisited[iPos + +iPos / 2] = true;
				qPos.push(iPos + +iPos / 2);
			}
		}
	}

	if (vecVisited[iN])
	{
		cout << "minigimbob\n";
	}
	else
	{
		cout << "water\n";
	}
	return 0;
}
