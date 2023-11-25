#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iS;
	cin >> iN >> iS;

	int iNow = 0;
	for (int i = 0; i < iN; ++i)
	{
		int iAdd;
		cin >> iAdd;

		if (iNow > iS)
		{
			--iNow;
		}

		iNow += iAdd;
	}

	cout << iNow << "\n";
	return 0;
}
