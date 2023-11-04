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

	string strAns = "";
	int iMin = 201;

	string strCity;
	int iTemp;
	while (cin >> strCity >> iTemp)
	{
		if (iTemp < iMin)
		{
			iMin = iTemp;
			strAns = strCity;
		}
	}
	
	cout << strAns << "\n";
	return 0;
}
