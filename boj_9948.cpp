#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string arrMonth[13] = { "", "January", "February", "March", "April", "May", "June", "July",
"August", "September", "October", "November", "December"};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iN;
		string strWord;
		cin >> iN >> strWord;

		if (iN == 0 && strWord == "#") break;

		int iMonth = 0;
		for (int i = 1;i <= 12;++i)
		{
			if (strWord == arrMonth[i])
			{
				iMonth = i;
			}
		}

		int iTotal = iMonth * 100 + iN;

		if (iTotal == 804)
		{
			cout << "Happy birthday" << "\n";
		}
		else if (iTotal == 229)
		{
			cout << "Unlucky" << "\n";

		}
		else if (iTotal > 804)
		{
			cout << "No" << "\n";
		}
		else
		{
			cout << "Yes" << "\n";
		}
	}
	return 0;
}
