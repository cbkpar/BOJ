#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB, iC;
	cin >> iA >> iB >> iC;

	iA %= 16;
	iB %= 16;
	iC %= 16;

	iA <<= 8;
	iB <<= 4;

	int iSum = iA + iB + iC;
	printf("%04d\n", iSum);
	return 0;
}
