#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN;
	cin >> iN;

	int iSum = 0;
	for (int i = 0;i < iN;++i)
	{
		string strTime;
		cin >> strTime;

		iSum += (strTime[0] - '0') * 600;
		iSum += (strTime[1] - '0') * 60;
		iSum += (strTime[3] - '0') * 10;
		iSum += (strTime[4] - '0') * 1;
	}

	printf("%02d:%02d:%02d\n", (iSum / 3600), (iSum % 3600) / 60, iSum % 60);
	return 0;
}
