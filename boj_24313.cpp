#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lA, lB, lC, lD;
	cin >> lA >> lB >> lC >> lD;

	if (lA <= lC)
	{
		if (lA * lD + lB <= lC * lD)
		{
			cout << "1\n";
		}
		else
		{
			cout << "0\n";
		}
	}
	else
	{
		cout << "0\n";
	}
	return 0;
}
