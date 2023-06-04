#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lL, lR, lB, lK;
	cin >> lL >> lR >> lB >> lK;

	long long lMinimum = (lL + lB - 1) / lB;
	cout << (lMinimum * lB * lK);
	return 0;
}
