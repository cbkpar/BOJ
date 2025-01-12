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

	int iA, iB, iC, iD;
	cin >> iA >> iB >> iC >> iD;

	int iSum = iA + iB + iC + iD - 2;
	iSum = (iSum % 4) + 1;
	cout << iSum << "\n";
	return 0;
}
