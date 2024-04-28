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

	int iLen;
	string strCup;
	cin >> iLen >> strCup;

	int iAns = 0;
	int iNow = 0;
	for (int i = 0; i < iLen; ++i)
	{
		if (strCup[i] == '1')
		{
			iNow = 3;
		}
		if (iNow > 0)
		{
			--iNow;
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
