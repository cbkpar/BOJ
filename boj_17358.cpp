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
	for (long long i = lN - 1; i > 1; i -= 2)
	{
		lAns = (lAns * i) % 1000000007;
	}
	cout << lAns << "\n";
	return 0;
}
