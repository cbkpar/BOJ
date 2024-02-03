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

	cout << (iA + iB - iC) << "\n";

	if (iB >= 1000) iA *= 10;
	if (iB >= 100) iA *= 10;
	if (iB >= 10) iA *= 10;
	if (iB >= 1) iA *= 10;
	iA += iB;

	cout << (iA - iC) << "\n";
	return 0;
}
