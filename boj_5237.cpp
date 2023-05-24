#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int>& parent, const int vertex) {
	if (parent[vertex] == vertex) return vertex;
	return parent[vertex] = find(parent, parent[vertex]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN, iK;
		cin >> iN >> iK;

		vector<int> vecParent(iN, 0);
		for (int i = 0; i < iN; ++i) vecParent[i] = i;

		int iCount = 0;
		while (iK--)
		{
			int iS, iE;
			cin >> iS >> iE;
			iS = find(vecParent, iS);
			iE = find(vecParent, iE);
			if (iS != iE)
			{
				++iCount;
				vecParent[iE] = iS;
			}
		}
		if (iCount == iN - 1)
		{
			cout << "Connected.\n";
		}
		else
		{
			cout << "Not connected.\n";
		}
	}
	return 0;
}
