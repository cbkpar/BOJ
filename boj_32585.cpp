#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN;
	cin >> iN;

	long long lAns = 0;
	long long lNow = 0;
	for (long long i = 1;i <= iN;++i)
	{
		lNow += i;
		lAns += lNow;
	}

	cout << lAns << "\n";
	return 0;
}
