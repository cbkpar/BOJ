#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long llN, llM, lla, llK;
	cin >> llN >> llM >> lla >> llK;

	long long llLastOther = lla - llK;
	long long llMin = llLastOther + 1;
	if (llMin > llN)
	{
		llMin = llN;
	}
	long long llMax = (llLastOther + llM - 1) / llM + 1;
	cout << llMin << " " << llMax << "\n";
	return 0;
}
