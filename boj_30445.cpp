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

	string strLine;
	getline(cin, strLine);

	int iHappy = 0;
	int iSad = 0;

	for (char ch : strLine)
	{
		if (ch == 'H') ++iHappy;
		if (ch == 'A') ++iHappy;
		if (ch == 'P') ++iHappy;
		if (ch == 'Y') ++iHappy;

		if (ch == 'S') ++iSad;
		if (ch == 'A') ++iSad;
		if (ch == 'D') ++iSad;
	}

	if (iHappy == 0 && iSad == 0)
	{
		cout << "50.00" << "\n";
	}
	else
	{
		int iAns = iHappy * 100000 / (iHappy + iSad);
		if (iAns % 10 >= 5) iAns += 10;
		iAns /= 10;

		printf("%d.%02d\n", iAns / 100, iAns % 100);
	}
	return 0;
}
