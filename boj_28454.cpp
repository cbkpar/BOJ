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

	string strStandard;
	cin >> strStandard;

	int iAns = 0;

	int iN;
	cin >> iN;
	while (iN--)
	{
		string strDate;
		cin >> strDate;

		if (strStandard.compare(strDate) <= 0) ++iAns;
	}
	
	cout << iAns << "\n";
	return 0;
}
