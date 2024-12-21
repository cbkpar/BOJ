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

	int iA, iB, iC;
	cin >> iA >> iB >> iC;

	bool bPossible = true;

	if (iA != 1 && iA != 3) bPossible = false;
	if (iB != 6 && iB != 8) bPossible = false;
	if (iC != 2 && iC != 5) bPossible = false;

	cout << (bPossible ? "JAH" : "EI") << "\n";
	return 0;
}
