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

	int iN;
	cin >> iN;

	string strWord;
	cin >> strWord;

	int iU = 0;
	int iO = 0;
	int iS = 0;
	int iP = 0;
	int iC = 0;

	for (char ch : strWord)
	{
		if (ch == 'u') ++iU;
		if (ch == 'o') ++iO;
		if (ch == 's') ++iS;
		if (ch == 'p') ++iP;
		if (ch == 'c') ++iC;
	}

	int iAns = iN;
	iAns = min(iAns, iU);
	iAns = min(iAns, iO);
	iAns = min(iAns, iS);
	iAns = min(iAns, iP);
	iAns = min(iAns, iC);

	cout << iAns << "\n";
	return 0;
}
