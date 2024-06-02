#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<pair<int, int>> vecNode(iN, { 0,0 });
	vector<int> vecCount(iN + 1, 0);

	for (int i = 1; i < iN; ++i)
	{
		cin >> vecNode[i].first >> vecNode[i].second;
		++vecCount[vecNode[i].first];
		++vecCount[vecNode[i].second];
	}

	int iM;
	cin >> iM;
	while (iM--)
	{
		int iT, iK;
		cin >> iT >> iK;

		if (iT == 1)
		{
			if (vecCount[iK] >= 2)
			{
				cout << "yes" << "\n";
			}
			else
			{
				cout << "no" << "\n";
			}
		}
		else
		{
			cout << "yes" << "\n";
		}
	}
	return 0;
}
