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

	long long lSum = 0;
	long long lMax = 0;
	for (int i = 0; i < iN; ++i)
	{
		long long lCount;
		cin >> lCount;

		lSum += lCount;
		lMax = max(lMax, lCount);
	}
	if (lSum == 1)
	{
		cout << "Happy" << "\n";
	}
	else
	{
		if (lSum / 2 + 1 <= lMax)
		{
			cout << "Unhappy" << "\n";
		}
		else
		{
			cout << "Happy" << "\n";
		}
	}

	return 0;
}
