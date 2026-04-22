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
	while (iT-- > 0)
	{
		long long lN;
		cin >> lN;

		long long lTemp = 1;

		int iK = 0;
		while (lN > lTemp)
		{
			lTemp *= 5;
			++iK;
		}

		if (iK < 2)
		{
			cout << "MIT time" << "\n";
		}
		else
		{
			cout << "MIT^" << iK << " time" << "\n";
		}
	}

	return 0;
}
