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

	long long lNum = 0;
	for (char ch : strDate)
	{
		lNum *= 10;
		if (ch != '-')
		{
			lNum += ch - '0';
		}
	}

	if (lNum <= 2023009016)
	{
		cout << "GOOD" << "\n";
	}
	else
	{
		cout << "TOO LATE" << "\n";
	}
	return 0;
}
