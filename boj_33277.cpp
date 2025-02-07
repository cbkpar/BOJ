#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB;
	cin >> iA >> iB;

	iB *= 1440;
	iB /= iA;

	int iH = iB / 60;
	int iM = iB % 60;
	printf("%02d:%02d\n", iH, iM);

	return 0;
}
