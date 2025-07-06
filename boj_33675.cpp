#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT-- > 0)
	{
		int iN;
		cin >> iN;

		long long lAns = 1;
		if (iN % 2 == 0)
		{
			lAns <<= (iN / 2);
			cout << lAns << "\n";
		}
		else
		{
			cout << "0" << "\n";
		}
	}

	return 0;
}
