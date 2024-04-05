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
	string strCommand;
	cin >> strCommand;

	int iNow = 1;
	int iAns = 0;
	for (char ch : strCommand)
	{
		if (ch == 'L')
		{
			--iNow;
			if (iNow < 1) iNow = 1;
		}
		else
		{
			++iNow;
			if (iNow > 3) iNow = 3;
		}
		if (iNow == 3) ++iAns;
	}

	cout << iAns << "\n";
	return 0;
}
