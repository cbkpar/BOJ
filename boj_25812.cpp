#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iR;
	cin >> iN >> iR;

	int iCountStatic = 0;
	int iCountDouble = 0;

	for (int i = 0;i < iN;++i)
	{
		int iNow;
		cin >> iNow;
		if (iNow >= iR) ++iCountDouble;
		if (iNow <= iR) ++iCountStatic;
	}

	if (iCountStatic > iCountDouble)
	{
		cout << "1" << "\n";
	}
	else if (iCountStatic < iCountDouble)
	{
		cout << "2" << "\n";
	}
	else
	{
		cout << "0" << "\n";
	}

	return 0;
}
