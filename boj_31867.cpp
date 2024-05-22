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

	string strDigit;
	cin >> strDigit;

	int iAns = 0;
	for (int i = 0;i < iN;++i)
	{
		if ((strDigit[i] - '0') % 2 == 0)
		{
			--iAns;
		}
		else
		{
			++iAns;
		}
	}

	if (iAns < 0) cout << "0" << "\n";
	if (iAns > 0) cout << "1" << "\n";
	if (iAns == 0) cout << "-1" << "\n";
	return 0;
}
