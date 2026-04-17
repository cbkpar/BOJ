#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iT;
	cin >> iT;

	for (int t = 0;t < iT;++t)
	{
		long long lN, lS;
		cin >> lN >> lS;

		if (lS - lN == 10000000)
		{
			cout << "Yes" << "\n";
		}
		else
		{
			cout << "No" << "\n";
		}

	}
	return 0;
}
