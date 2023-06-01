#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iH, iM, iS;
	cin >> iH >> iM >> iS;

	++iS;
	if (iS >= 60)
	{
		++iM;
		iS -= 60;
	}

	if (iM >= 60)
	{
		++iH;
		iM -= 60;
	}

	iH %= 24;

	printf("%02d:%02d:%02d\n", iH, iM, iS);
	return 0;
}
