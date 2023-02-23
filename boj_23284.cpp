#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int iN;
int iAns[10] = { 0, };
bool bUsed[11] = { false, };

void BackTracking(int iMax, int k)
{
	if (k == iN)
	{
		for (int i = 0; i < iN; ++i)
		{
			cout << iAns[i] << (i == iN - 1 ? "\n" : " ");
		}
		return;
	}
	for (int i = iMax - 1; i >= 1; --i)
	{
		if (!bUsed[i])
		{
			bUsed[i] = true;
			iAns[k] = i;
			BackTracking(i, k + 1);
			bUsed[i] = false;
			break;
		}
	}
	for (int i = iMax + 1; i <= iN; ++i)
	{
		if (!bUsed[i])
		{
			bUsed[i] = true;
			iAns[k] = i;
			BackTracking(i, k + 1);
			bUsed[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iN;
	BackTracking(0, 0);

	return 0;
}
