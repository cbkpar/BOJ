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

	int iN, iM, iK;
	cin >> iN >> iM >> iK;

	int iSize = iM * 2 + 3;

	string strTop, strBottom;
	strTop.resize(iSize);
	strBottom.resize(iM + 2);

	for (int i = 0; i < iSize; ++i) strTop[i] = ' ';
	strTop[0] = '*';
	strTop[iM+1] = '*';
	strTop[iM*2+2] = '*';
	for (int i = 0; i < iN; ++i) cout << strTop << "\n";
	for (int i = 0; i < iSize; ++i) strTop[i] = '*';
	cout << strTop << "\n";

	for (int i = 0; i <= iM; ++i) strBottom[i] = ' ';
	strBottom[iM + 1] = '*';
	for (int i = 0; i < iK; ++i) cout << strBottom << "\n";
	return 0;
}
