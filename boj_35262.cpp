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

	int iN, iK;
	cin >> iN >> iK;

	string strCommand;
	cin >> strCommand;

	int iMax = 0;
	int iNow = 0;
	for (int i = 0; i < iN; ++i)
	{
		if (strCommand[i] == '0')
		{
			++iNow;
		}
		else
		{
			iNow = 0;
		}
		iMax = max(iMax, iNow);
	}

	cout << (iMax < iK ? "1" : "0") << "\n";
	return 0;
}
