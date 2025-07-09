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

	string strDate;
	cin >> strDate;

	int iMonth = (strDate[3] - '0') * 10 + (strDate[4] - '0');
	int iDay = (strDate[0] - '0') * 10 + (strDate[1] - '0');

	if (iMonth <= 12 && iDay <= 12)
	{
		cout << "either" << "\n";
	}
	else if (iMonth > 12)
	{
		cout << "US" << "\n";
	}
	else
	{
		cout << "EU" << "\n";
	}

	return 0;
}
