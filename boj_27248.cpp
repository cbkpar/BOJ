#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int iN, iT;
int iNow = 0;
bool bFound = false;
int vecNum[1001] = { 0, };
bool vecUsed[1001] = { false, };

void DFS(int iK)
{
	if (bFound) return;
	if (iK == iN)
	{
		++iNow;
		if (iNow == iT)
		{
			bFound = true;
		}
		for (int i = 0;i < iN;++i)
		{
			cout << vecNum[i] << (i == iN - 1 ? "\n" : " ");
		}
	}

	for (int i = 1;i <= iN;++i)
	{
		if (i - 1 == iK) continue;
		if (!vecUsed[i])
		{
			vecUsed[i] = true;
			vecNum[iK] = i;
			DFS(iK + 1);
			vecUsed[i] = false;
		}
	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iN >> iT;
	DFS(0);

	return 0;
}
