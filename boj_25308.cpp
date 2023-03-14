#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long Ability[8] = { 0, };
int iAns = 0;
int Choose[8] = { 0, };
bool Used[8] = { false, };

void DFS(int iK)
{
	if (iK == 8)
	{
		for (int i = 0; i < 8; ++i)
		{
			long long lA = Ability[Choose[(i % 8)]];
			long long lB = Ability[Choose[((i + 1) % 8)]];
			long long lC = Ability[Choose[((i + 2) % 8)]];
			long long lDiff = 2 * lA * lA * lC * lC - (lA + lC) * (lA + lC) * lB * lB;
			if (lDiff > 0) return;
		}
		++iAns;
		return;
	}
	for (int i = 0; i < 8; ++i)
	{
		if (!Used[i])
		{
			Used[i] = true;
			Choose[iK] = i;
			DFS(iK + 1);
			Used[i] = false;
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 8; ++i)
	{
		cin >> Ability[i];
	}
	DFS(0);
	cout << iAns << "\n";
	return 0;
}
