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

	while (true)
	{
		int iCheryl = 0;
		int iTania = 0;
		bool bEnd = false;
		while (true)
		{
			string strCommand;
			cin >> strCommand;
			if (strCommand == "#")
			{
				bEnd = true;
				break;
			}

			if (strCommand == "*")
			{
				if(iCheryl > iTania)
				{
					cout << "Cheryl" << "\n";
				}
				else if (iCheryl < iTania)
				{
					cout << "Tania" << "\n";
				}
				else
				{
					cout << "Draw" << "\n";
				}
				break;
			}

			if (strCommand == "A") ++iCheryl;
			if (strCommand == "2") ++iTania;
			if (strCommand == "3") ++iCheryl;
			if (strCommand == "4") ++iTania;
			if (strCommand == "5") ++iCheryl;
			if (strCommand == "6") ++iTania;
			if (strCommand == "7") ++iCheryl;
			if (strCommand == "8") ++iTania;
			if (strCommand == "9") ++iCheryl;
			if (strCommand == "10") ++iTania;

		}
		if (bEnd)
		{
			break;
		}
	}

	return 0;
}
