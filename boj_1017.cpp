#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Bipartite(const vector<vector<int>>& Node, vector<bool>& Visited, vector<int>& Next, int now, int except)
{
	for (int next : Node[now])
	{
		if (Visited[next] || next == except) continue;
		Visited[next] = true;

		if (Next[next] == -1 || Bipartite(Node, Visited, Next, Next[next], except))
		{
			Next[next] = now;
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool ArrPrime[2001] = { false, };
	for (int i = 2; i * i <= 2000; i++) {
		for (int j = i * i; j <= 2000; j += i) {
			ArrPrime[j] = true;
		}
	}
	ArrPrime[0] = ArrPrime[1] = true;

	int iN;
	cin >> iN;
	vector<int> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	vector<vector<int>> vecNode(iN, vector<int>());
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			if (i == j) continue;
			if (!ArrPrime[vecNum[i] + vecNum[j]])
			{
				vecNode[i].push_back(j);
			}
		}
	}

	vector<int> vecAns;
	for (int k : vecNode[0])
	{
		vector<int> vecNext(iN, -1);
		vecNext[0] = k;
		vecNext[k] = 0;
		for (int i = 1; i < iN; ++i)
		{
			if (i == k) continue;
			vector<bool> vecVisited(iN, false);
			Bipartite(vecNode, vecVisited, vecNext, i, k);
		}
		int iCount = 0;
		for (int i = 0; i < iN; ++i)
		{
			if (vecNext[i] >= 0) ++iCount;
		}
		if (iCount == iN)
		{
			vecAns.push_back(vecNum[k]);
		}
	}

	if (!vecAns.empty())
	{
		int iSize = vecAns.size();
		sort(vecAns.begin(), vecAns.end());
		for (int i = 0; i < iSize; ++i)
		{
			cout << vecAns[i] << (i == iSize - 1 ? "\n" : " ");
		}
	}
	else
	{
		cout << "-1\n";
	}
	return 0;
}
