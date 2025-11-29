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

	string strLine;
	cin >> strLine;

	int iAns = 0;
	bool bUp = false;
	bool bDown = false;

	for (int i = 0;i < iN;++i)
	{
		if (strLine[i] == '[')
		{
			bUp = true;
			bDown = true;
			++iAns;
		}
		else if (strLine[i] == ']')
		{
			if (bUp == false && bDown == false)
			{
				++iAns;
			}
			bUp = false;
			bDown = false;
		}
		else if (strLine[i] == '5')
		{
			if (bDown == false)
			{
				++iAns;
			}
			++iAns;
			bUp = true;
			bDown = false;
		}
		else if (strLine[i] == '2')
		{
			if (bUp == false)
			{
				++iAns;
			}
			++iAns;
			bUp = false;
			bDown = true;
		}
	}

	cout << iAns << "\n";
	return 0;

}
