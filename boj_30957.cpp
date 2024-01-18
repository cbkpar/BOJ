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

	int iB = 0;
	int iS = 0;
	int iA = 0;

	for (char ch : strWord)
	{
		if (ch == 'B') ++iB;
		if (ch == 'S') ++iS;
		if (ch == 'A') ++iA;
	}

	int iMax = max(iS, max(iB, iA));
	if (iB == iS && iS == iA)
	{
		cout << "SCU" << "\n";
	}
	else
	{
		if (iB == iMax) cout << "B";
		if (iS == iMax) cout << "S";
		if (iA == iMax) cout << "A";
		cout << "\n";
	}
	return 0;
}
