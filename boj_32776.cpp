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

	int iS;
	cin >> iS;

	int iMa, iFab, iMb;
	cin >> iMa >> iFab >> iMb;

	if (iS <= iMa + iFab + iMb || iS <= 240)
	{
		cout << "high speed rail" << "\n";
	}
	else
	{
		cout << "flight" << "\n";
	}

	return 0;
}
