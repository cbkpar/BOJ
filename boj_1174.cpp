#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> vecNum;

void dfs(long long lN, long long lK, long long lSum)
{
	for (long long i = lN; i <= 9; ++i)
	{
		long long lNext = i * lK + lSum;
		vecNum.push_back(lNext);
		dfs(i + 1, lK * 10, lNext);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dfs(0, 1, 0);
	sort(vecNum.begin(), vecNum.end());

	int iN;
	cin >> iN;

	if (iN > vecNum.size())
	{
		cout << "-1\n";
	}
	else
	{
		cout << vecNum[iN - 1] << "\n";
	}
	return 0;
}
