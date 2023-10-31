#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 1; t <= iT; ++t)
	{
		int iH, iM;
		cin >> iH >> iM;

		int iTime = (iH * 60 + iM);
		iTime = (iTime + 1440 - 45) % 1440;

		printf("Case #%d: %d %d\n", t, iTime / 60, iTime % 60);
	}

	return 0;
}
