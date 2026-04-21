#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int CalcDiff(int iH1, int iM1, int iH2, int iM2)
{
	int iRet = 0;
	iRet = (iH2 - iH1) * 60 + (iM2 - iM1);
	if (iRet < 0) iRet += 1440;

	return iRet;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iMin = 1440;
	int iMax = 0;

	for (int i = 0;i < 3;++i)
	{
		int iH1, iM1, iH2, iM2;
		cin >> iH1 >> iM1 >> iH2 >> iM2;

		int iDiff = CalcDiff(iH1, iM1, iH2, iM2);
		iMin = min(iMin, iDiff);
		iMax = max(iMax, iDiff);
	}

	printf("%d:%02d\n", (iMin / 60), (iMin % 60));
	printf("%d:%02d\n", (iMax / 60), (iMax % 60));
	return 0;
}
