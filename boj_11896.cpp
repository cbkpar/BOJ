#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long CalcCount(long long lN)
{
	if (lN < 4) return 0;
	lN /= 2;
	long long lTemp = lN * (lN + 1) / 2;
	lTemp -= 1;
	lTemp *= 2;
	return lTemp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lA, lB;
	cin >> lA >> lB;

	long long lAns = CalcCount(lB) - CalcCount(lA-1);
	cout << lAns << "\n";
	return 0;
}
