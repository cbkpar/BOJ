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
	for (int i = 0;i < iN;++i)
	{
		string strName;
		cin >> strName;

		int iYear;
		cin >> iYear;

		if (iYear == 2026)
		{
			cout << strName << "\n";
		}
	}
	return 0;
}
