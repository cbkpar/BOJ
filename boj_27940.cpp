#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;
	long long lK;
	cin >> lK;

	long long lSum = 0;
	for (int i = 1; i <= iM; ++i)
	{
		int iT;
		long long lR;
		cin >> iT >> lR;
		lSum += lR;
		if (lSum > lK)
		{
			cout << i << " 1\n";
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}
