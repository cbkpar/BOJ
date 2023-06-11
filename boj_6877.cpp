#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iMaxR, iMaxC;
	cin >> iMaxR >> iMaxC;

	int iNowR = 0;
	int iNowC = 0;

	while (true)
	{
		int iR, iC;
		cin >> iR >> iC;
		if (iR == 0 && iC == 0) break;
		iNowR += iR;
		iNowC += iC;
		if (iNowR < 0) iNowR = 0;
		if (iNowR > iMaxR) iNowR = iMaxR;
		if (iNowC < 0) iNowC = 0;
		if (iNowC > iMaxC) iNowC = iMaxC;
		cout << iNowR << " " << iNowC << "\n";
	}
	return 0;
}
