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

	int iN, iD;
	cin >> iN >> iD;

	cout << "+---------------------+\n";
	int iNow = 0;
	while (iNow < iN)
	{
		string strTemp = "|.....................|";
		for (int i = iD; i <= 7; ++i)
		{
			++iNow;
			int iTemp = iNow;
			strTemp[3 * i] = (char)(iTemp % 10 + '0');
			if (iTemp >= 10) strTemp[3 * i - 1] = (char)(iTemp / 10 + '0');
			if (iNow >= iN) break;
		}
		iD = 1;
		cout << strTemp << "\n";
	}
	cout << "+---------------------+\n";
	return 0;
}
