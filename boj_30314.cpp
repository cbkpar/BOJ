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

	string strA, strB;
	cin >> strA >> strB;

	int iAns = 0;
	for (int i = 0;i < iN;++i)
	{
		int iA = strA[i] - 'A';
		int iB = strB[i] - 'A';
		int iDiff = (iA - iB + 26) % 26;
		if (iDiff > 13) iDiff = 26 - iDiff;
		iAns += iDiff;
	}

	cout << iAns << "\n";
	return 0;
}
