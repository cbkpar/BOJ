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

	int iNow = 0;
	for (int i = 0;i < iN;++i)
	{
		int iCommand, iCount;
		cin >> iCommand >> iCount;

		if (iCommand == 1)
		{
			iNow += iCount;
		}

		if (iCommand == 2)
		{
			iNow -= iCount;
		}

		if (iNow < 0)
		{
			cout << "Adios" << "\n";
			return 0;
		}
	}

	cout << "See you next month" << "\n";
	return 0;
}
