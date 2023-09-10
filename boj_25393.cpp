#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecLeft(1000001, -1);
	vector<int> vecRight(1000001, 10000001);
	vector<set<int>> setLeft(1000001, set<int>());
	vector<set<int>> setRight(1000001, set<int>());

	int iN;
	cin >> iN;
	while (iN--)
	{
		int iS, iE;
		cin >> iS >> iE;

		vecLeft[iS] = max(vecLeft[iS], iE);
		vecRight[iE] = min(vecRight[iE], iS);

		setLeft[iS].insert(iE);
		setRight[iE].insert(iS);
	}

	int iQ;
	cin >> iQ;
	while (iQ--)
	{
		bool bLeft = false;
		bool bRight = false;

		int iAns = -1;

		int iS, iE;
		cin >> iS >> iE;

		if (setLeft[iS].find(iE) != setLeft[iS].end())
		{
			iAns = 1;
		}
		else
		{
			if (vecLeft[iS] != -1 && vecRight[iE] != 10000001)
			{
				if (vecLeft[iS] >= iE && vecRight[iE] <= iS)
				{
					iAns = 2;
				}
			}
		}
		cout << iAns << "\n";
	}
	return 0;
}
