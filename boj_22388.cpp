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

	while (true)
	{
		string strWord;
		cin >> strWord;

		if (strWord == "#") break;

		int iY, iM, iD;
		cin >> iY >> iM >> iD;

		if ((iY >= 31 && iM >= 5) || (iY >= 32))
		{
			cout << "? " << (iY - 30) << " " << iM << " " << iD << "\n";

		}
		else
		{
			cout << "HEISEI " << iY << " " << iM << " " << iD << "\n";
		}
	}
	return 0;
}
