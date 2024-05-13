#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN, lM;
	cin >> lN >> lM;

	if (lN >= lM)
	{
		cout << "0" << "\n";
		return 0;
	}

	long long lNum = 1;
	for (long long i = 1;i <= lN;++i)
	{
		lNum = (lNum * i) % lM;
	}

	cout << lNum << "\n";
	return 0;
}
