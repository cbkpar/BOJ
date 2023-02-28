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

	int iR;
	cin >> iR;

	int iDivision = 0;
	if (iR <= 1600) iDivision = 3;
	if (iR > 1600 && iR <= 1900) iDivision = 2;
	if (iR > 1900) iDivision = 1;

	string strDivision;
	cin >> strDivision;

	bool bDivision[4] = { false, };
	for (char ch : strDivision)
	{
		bDivision[ch - '0'] = true;
	}
	if (bDivision[iDivision])
	{
		cout << iDivision << "\n";
	}
	else
	{
		if (bDivision[1])
		{
			cout << "1\n";
		}
		if (bDivision[2])
		{
			cout << "2" << (iR > 1900 ? "*" : "") << "\n";
		}
		if (bDivision[3])
		{
			cout << "3" << (iR > 1600 ? "*" : "") << "\n";
		}
	}

	return 0;
}
