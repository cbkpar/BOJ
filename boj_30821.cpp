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

	long long lAns = 1;
	for (long long i = 0; i < 5; ++i)
	{
		lAns *= (lN - i);
	}
	lAns /= 120;

	cout << lAns << "\n";
	return 0;
}
