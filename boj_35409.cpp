#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iH, iM;
	cin >> iH >> iM;

	int iTime = iH * 60 + iM;

	bool bPossible = false;
	if (iTime >= 6 * 60 + 30 && iTime <= 9 * 60 + 0) bPossible = true;
	if (iTime >= 9 * 60 + 50 && iTime <= 10 * 60 + 0) bPossible = true;
	if (iTime >= 10 * 60 + 50 && iTime <= 11 * 60 + 0) bPossible = true;
	if (iTime >= 11 * 60 + 50 && iTime <= 12 * 60 + 0) bPossible = true;
	if (iTime >= 12 * 60 + 50 && iTime <= 13 * 60 + 50) bPossible = true;
	if (iTime >= 14 * 60 + 40 && iTime <= 14 * 60 + 50) bPossible = true;
	if (iTime >= 15 * 60 + 40 && iTime <= 15 * 60 + 50) bPossible = true;
	if (iTime >= 16 * 60 + 40 && iTime <= 22 * 60 + 50) bPossible = true;

	cout << (bPossible ? "Yes" : "No") << "\n";
	return 0;
}
