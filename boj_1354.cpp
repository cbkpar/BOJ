#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long lP, lQ, lX, lY;
long long lNum[1000001] = { 0, };


long long divide(long long lN)
{
	if (lN <= 0) return 1;
	if (lN <= 1000000)
	{
		if (lNum[lN] != 0) return lNum[lN];
		return lNum[lN] = divide((lN / lP) - lX) + divide((lN / lQ) - lY);
	}
	return divide((lN / lP) - lX) + divide((lN / lQ) - lY);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN;
	cin >> lN >> lP >> lQ >> lX >> lY;

	cout << divide(lN) << "\n";
	return 0;
}
