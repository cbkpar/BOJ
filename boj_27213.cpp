#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	if (iN == 1 || iM == 1)
	{
		cout << (iN * iM) << "\n";
	}
	else
	{
		cout << (iN + iM - 2) * 2 << "\n";
	}

	return 0;
}
