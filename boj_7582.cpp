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
		string strName;
		int iMax;
		cin >> strName >> iMax;

		if (strName == "#" && iMax == 0) break;

		int iNow;
		cin >> iNow;

		int iN;
		cin >> iN;
		while (iN--)
		{
			int iOut, iIn;
			cin >> iOut >> iIn;
			iNow -= iOut;
			iNow += iIn;
			if (iNow > iMax) iNow = iMax;
		}
		cout << strName << " " << iNow << "\n";
	}

	return 0;
}
