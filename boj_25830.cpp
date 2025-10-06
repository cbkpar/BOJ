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

	string strTime;
	cin >> strTime;

	int iMin = (strTime[0] - '0') * 10 + (strTime[1] - '0');
	int iSecond = (strTime[3] - '0') * 10 + (strTime[4] - '0');

	int iTotal = (iMin * 3600 + iSecond * 60) - (iMin * 60 + iSecond);

	printf("%02d:%02d:%02d\n", iTotal / 3600, (iTotal % 3600) / 60, iTotal % 60);
	return 0;
}
