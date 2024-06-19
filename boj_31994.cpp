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

	int iMax = -1;
	string strAns = "";

	for (int i = 0;i < 7;++i)
	{
		string strName;
		int iCount;
		cin >> strName >> iCount;

		if (iCount > iMax)
		{
			iMax = iCount;
			strAns = strName;
		}
	}

	cout << strAns << "\n";
	return 0;
}
