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

	int iAns = 0;
	long long lTemp = 1;
	while (true)
	{
		if (lN < lTemp * lTemp) break;
		lN -= lTemp * lTemp;
		++iAns;
		lTemp += 2;
	}

	cout << iAns << "\n";
	return 0;
}
