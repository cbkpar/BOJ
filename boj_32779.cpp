#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	while (iN-- > 0)
	{
		long long lA, lM;
		cin >> lA >> lM;

		long long lTotal = lA * lM * 1056L / 600000L;
		cout << lTotal << "\n";
	}
	return 0;
}
