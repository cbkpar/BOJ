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

	long long lM;
	cin >> lM;

	long long lSum = 0;
	for (int i = 0;i < iN;++i)
	{
		long long lNum;
		cin >> lNum;

		lSum += lNum - 1;
	}

	if (lM > lSum)
	{
		cout << "OUT" << "\n";
	}
	else
	{
		cout << "DIMI" << "\n";
	}

	return 0;
}
