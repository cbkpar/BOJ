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

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN;
		cin >> iN;

		set<int> setLeft;
		for (int i = 0; i < iN; ++i)
		{
			int iNum;
			cin >> iNum;
			setLeft.insert(iNum);
		}
		vector<int> vecRight(iN);
		for (int i = 0; i < iN; ++i) cin >> vecRight[i];
		sort(vecRight.begin(), vecRight.end());

		int iAns = 0;
		set<int> setRight;
		for (int i = 0; i < iN; ++i)
		{
			setRight.insert(vecRight[i]);
			if (setLeft.find(vecRight[i] - 1500) == setLeft.end()) continue;
			if (setLeft.find(vecRight[i] - 1000) == setLeft.end()) continue;
			if (setRight.find(vecRight[i] - 500) == setRight.end()) continue;
			++iAns;
		}
		cout << iAns << "\n";
	}
	return 0;
}
