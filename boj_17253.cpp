#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN;
	cin >> lN;
	if (lN == 0)
	{
		cout << "NO\n";
		return 0;
	}
	while (lN)
	{
		long long lRest = lN % 3;
		lN /= 3;

		if (lRest == 2)
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}
