#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lK, lA, lB, lC, lD;
	cin >> lK >> lA >> lB >> lC >> lD;

	long long lLeft = lK * lA + lB;
	long long lRight = lK * lC + lD;

	if (lLeft == lRight)
	{
		cout << "Yes " << lLeft << "\n";
	}
	else
	{
		cout << "No\n";
	}
	return 0;
}
