#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM, iP;
	cin >> iN >> iM >> iP;

	cout << (iN * 2) << " " << (iN * iN) << "\n";
	for (int i = 1; i <= iN; ++i)
	{
		for (int j = iN + 1; j <= iN * 2; ++j)
		{
			cout << i << " " << j << "\n";
		}
	}
	return 0;
}
