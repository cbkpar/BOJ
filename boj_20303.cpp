#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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

	int iN, iM, iK;
	cin >> iN >> iM >> iK;

	vector<int> vecNum(iN + 1, 0);
	for (int i = 1; i <= iN; ++i) cin >> vecNum[i];

	vector<int> vecParent(iN + 1, 0);
	for (int i = 1; i <= iN; ++i) vecParent[i] = i;

	while (iM--)
	{
		int iA, iB;
		cin >> iA >> iB;
		union_vertices(vecParent, iA, iB);
	}

	vector<int> vecSum(iN + 1, 0);
	vector<int> vecCount(iN + 1, 0);
	for (int i = 1; i <= iN; ++i)
	{
		int iParent = find(vecParent, i);
		vecSum[iParent] += vecNum[i];
		vecCount[iParent] += 1;
	}

	vector<bool> vecVisited(iN + 1, false);
	vector<int> vecAns(iK, 0);

	for (int i = 1; i <= iN; ++i)
	{
		int iParent = find(vecParent, i);
		if (!vecVisited[iParent])
		{
			vecVisited[iParent] = true;
			for (int j = iK - 1; j >= vecCount[iParent]; --j)
			{
				vecAns[j] = max(vecAns[j], vecAns[j - vecCount[iParent]] + vecSum[iParent]);
			}
		}
	}
	int iAns = 0;
	for (int i = 0; i < iK; ++i)
	{
		iAns = max(iAns, vecAns[i]);
	}
	cout << iAns << "\n";
	return 0;
}
