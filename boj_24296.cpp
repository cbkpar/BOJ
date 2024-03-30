#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	while (iN > 1)
	{
		if (iN % 2 == 0) break;
		iN = (iN + 1) / 2;
	}

	cout << iN << "\n";
	return 0;
}
