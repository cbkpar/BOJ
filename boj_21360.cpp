#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	string strSeat;
	cin >> strSeat;

	int iAns = 1000000;
	int iPos = -1000000;
	for (int i = 0; i < iN; ++i)
	{
		if (strSeat[i] == '.')
		{
			iAns = min(iAns, i - iPos - 1);
			iPos = i;
		}
	}
	cout << iAns << "\n";
	return 0;
}
