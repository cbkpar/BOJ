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

	string strWord;
	cin >> strWord;

	int iS = 0;
	int iE = strWord.length() - 1;

	int iN;
	cin >> iN;
	while (iN--)
	{
		int iTempS, iTempE;
		cin >> iTempS >> iTempE;

		iS += iTempS;
		iE = iTempE;
	}
	cout << strWord.substr(iS, iE) << "\n";
	return 0;
}
