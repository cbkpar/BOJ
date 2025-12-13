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

	string strAns;
	cin >> strAns;

	bool bLeft = true;
	int iCount = 0;
	for (int i = 0;i < iN;++i)
	{
		if (strAns[i] == 'L')
		{
			if (bLeft)
			{
				bLeft = false;
			}
			else
			{
				iCount += 1;
			}
		}
		else
		{
			if (!bLeft)
			{
				bLeft = true;
			}
			else
			{
				iCount += 1;
			}
		}
	}

	int iAns = iK - iCount;
	if (iAns < 0) iAns = 0;
	cout << iAns << "\n";

	return 0;
}
