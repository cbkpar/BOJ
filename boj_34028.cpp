#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iYear, iMonth, iDay;
	cin >> iYear >> iMonth >> iDay;

	int iAns = 0;
	if (iYear < 2015)
	{

	}
	else if (iYear == 2015)
	{
		if (iMonth == 1)
		{
			if (iDay < 16)
			{

			}
			else
			{
				++iAns;
			}
		}
		else
		{
			iAns += iMonth / 3 + 1;
		}
	}
	else
	{
		iAns += (iYear - 2015) * 4;
		iAns += iMonth / 3 + 1;
	}

	cout << iAns << "\n";
	return 0;
}
