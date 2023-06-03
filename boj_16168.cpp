#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int>& parent, const int vertex) {
	if (parent[vertex] == vertex) return vertex;
	return parent[vertex] = find(parent, parent[vertex]);
}

void union_vertices(vector<int>& parent, int u, int v) {
	u = find(parent, u);
	v = find(parent, v);
	if (u != v) parent[u] = v;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<int> vecNode(iN + 1, 0);
	vector<int> vecParent(iN + 1, 0);
	for (int i = 1; i <= iN; ++i) vecParent[i] = i;

	while (iM--)
	{
		int iS, iE;
		cin >> iS >> iE;
		++vecNode[iS];
		++vecNode[iE];
		union_vertices(vecParent, iS, iE);
	}
	int iCount = 1;
	for (int i = 2; i <= iN; ++i)
	{
		int iU = find(vecParent, i);
		int iV = find(vecParent, i - 1);
		if (iU != iV) ++iCount;
	}
	if (iCount > 1)
	{
		cout << "NO\n";
		return 0;
	}

	int iOdd = 0;
	int iEven = 0;
	for (int i = 1; i <= iN; ++i)
	{
		if (vecNode[i] % 2 == 0)
		{
			++iEven;
		}
		else
		{
			++iOdd;
		}
	}

	if (iOdd == 0)
	{
		cout << "YES\n";
	}
	else if (iOdd == 2)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
	return 0;
}
