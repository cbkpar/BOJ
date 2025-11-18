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

	string strTime1, strTime2;
	cin >> strTime1 >> strTime2;

	int iTime1 = 0;
	int iTime2 = 0;

	iTime1 += (strTime1[0] - '0') * 1000;
	iTime1 += (strTime1[1] - '0') * 100;
	iTime1 += (strTime1[3] - '0') * 10;
	iTime1 += (strTime1[4] - '0') * 1;

	iTime2 += (strTime2[0] - '0') * 1000;
	iTime2 += (strTime2[1] - '0') * 100;
	iTime2 += (strTime2[3] - '0') * 10;
	iTime2 += (strTime2[4] - '0') * 1;

	if (iTime1 > iTime2)
	{
		cout << "NO" << "\n";
	}
	else
	{
		cout << "YES" << "\n";
	}

	return 0;
}
