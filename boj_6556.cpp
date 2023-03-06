#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		long long lN, lM;
		cin >> lN >> lM;
		if (lN == 0 && lM == 0) break;

		if (lN < lM) swap(lN, lM);
		if (lN == 0 || lM == 0)
		{
			cout << "1\n";
			continue;
		}
		if (lM == 1)
		{
			cout << (lN + 1) << "\n";
			continue;
		}
		long long lAns = 1;
		for (int i = 1; i <= lM; ++i)
		{
			lAns *= lN + lM - i + 1;
			lAns /= i;
		}
		cout << lAns << "\n";
	}

	return 0;
}
