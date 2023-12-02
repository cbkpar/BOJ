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

	string strSeat;
	cin >> strSeat;

	int iLen = strSeat.length();

	int iNum = 0;
	if (iLen == 3)
	{
		iNum = (strSeat[1] - '0') * 10 + (strSeat[2] - '0');
	}
	else
	{
		iNum = (strSeat[1] - '0');
	}

	if (strSeat[0] == 'R')
	{
		if (iNum > 0 && iNum <= 36)
		{
			cout << ((iNum-1)/4+1) << " " << "1" << " " << (iNum % 2 == 0 ? "1" : "-1") << "\n";
		}
		else if (iNum > 36 && iNum <= 54)
		{
			cout << (((55 - iNum) - 1) / 2 + 1) << " " << "0" << " " << (iNum % 2 == 0 ? "1" : "-1") << "\n";
		}
		else
		{
			cout << "-1" << "\n";
		}
	}
	else
	{
		if (iNum > 0 && iNum <= 36)
		{
			cout << ((iNum - 1) / 4 + 1) << " " << "1" << " " << (iNum % 2 == 0 ? "1" : "-1") << "\n";
		}
		else
		{
			cout << "-1" << "\n";
		}
	}

	return 0;
}
