#include <iostream>

using namespace std;

int main()
{
	int iT1, iM1, iT2, iM2;
	cin >> iT1 >> iM1 >> iT2 >> iM2;
	auto TotalMinute = [](int iHour, int iMinute)->int {return iHour * 60 + iMinute; };
	int iDeltaTime = [](int iTime1, int iTime2)->int {return (iTime2 - iTime1 + 1440) % 1440; }
	(TotalMinute(iT1, iM1), TotalMinute(iT2, iM2));
	cout << iDeltaTime << " " << (iDeltaTime / 30) << endl;
	return 0;
}
