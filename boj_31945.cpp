#include <iostream>
#include <vector>
#include <algorithm>

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
		vector<int> vecPoint(4, 0);
		for (int i = 0; i < 4; ++i)
		{
			cin >> vecPoint[i];
		}
		sort(vecPoint.begin(), vecPoint.end());

		bool bPossible = false;

		if (vecPoint[0] == 0 && vecPoint[1] == 1 && vecPoint[2] == 2 && vecPoint[3] == 3)
		{
			bPossible = true;
		}
		if (vecPoint[0] == 0 && vecPoint[1] == 2 && vecPoint[2] == 4 && vecPoint[3] == 6)
		{
			bPossible = true;
		}
		if (vecPoint[0] == 0 && vecPoint[1] == 1 && vecPoint[2] == 4 && vecPoint[3] == 5)
		{
			bPossible = true;
		}
		if (vecPoint[0] == 1 && vecPoint[1] == 3 && vecPoint[2] == 5 && vecPoint[3] == 7)
		{
			bPossible = true;
		}
		if (vecPoint[0] == 4 && vecPoint[1] == 5 && vecPoint[2] == 6 && vecPoint[3] == 7)
		{
			bPossible = true;
		}
		if (vecPoint[0] == 2 && vecPoint[1] == 3 && vecPoint[2] == 6 && vecPoint[3] == 7)
		{
			bPossible = true;
		}

		if (bPossible)
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
	}
	return 0;
}
