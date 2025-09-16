#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iAns = 0;
	if (iN % 2 == 0)
	{
		iAns = 2;
	}
	else
	{
		iAns = 1;
	}

	cout << iAns << "\n";
	return 0;
}
