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

	bool bPossible = false;

	if (iA == iB + iC) bPossible = true;
	if (iB == iA + iC) bPossible = true;
	if (iC == iB + iA) bPossible = true;

	cout << (bPossible ? "1" : "0") << "\n";
	return 0;
}
