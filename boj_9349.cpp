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
		int iN, iK;
		cin >> iN >> iK;

		int iAns = (iN - 1) / (iK - 1) - 1;
		cout << iAns << "\n";
	}

	return 0;
}
