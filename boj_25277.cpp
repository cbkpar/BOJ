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

	int iAns = 0;
	for (int i = 0;i < iN;++i)
	{
		string strWord;
		cin >> strWord;

		if (strWord == "he") ++iAns;
		if (strWord == "him") ++iAns;
		if (strWord == "she") ++iAns;
		if (strWord == "her") ++iAns;
	}

	cout << iAns << "\n";
	return 0;
}
