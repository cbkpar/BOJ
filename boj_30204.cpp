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
	long long lX;
	cin >> iN >> lX;

	long long lSum = 0;
	for (int i = 0; i < iN; ++i)
	{
		long long lNum;
		cin >> lNum;
		lSum += lNum;
	}

	cout << (lSum % lX == 0 ? "1" : "0") << "\n";
	return 0;
}
