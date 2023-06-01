#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int DateToInt(string& strDate)
{
	int iYear = 0;
	for (int i = 0; i < 4; ++i)
	{
		iYear *= 10;
		iYear += strDate[i] - '0';
	}
	return iYear;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		string strName, strPost, strBirth;
		int iCourse;
		cin >> strName >> strPost >> strBirth >> iCourse;

		if (DateToInt(strPost) >= 2010)
		{
			cout << strName << " " << "eligible" << "\n";
		}
		else if (DateToInt(strBirth) >= 1991)
		{
			cout << strName << " " << "eligible" << "\n";
		}
		else if (iCourse >= 41)
		{
			cout << strName << " " << "ineligible" << "\n";
		}
		else
		{
			cout << strName << " " << "coach petitions" << "\n";
		}
	}
	return 0;
}
