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

	long long lTemp = 1;
	long long lAns = 0;

	while (lN >= lTemp * lTemp)
	{
		lN -= lTemp * lTemp;
		++lTemp;
		++lAns;
	}
	cout << lAns << "\n";
	return 0;
}
