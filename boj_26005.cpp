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

	if (iN == 1)
	{
		cout << "0\n";
		return 0;
	}
	iN = iN * iN;
	cout << (iN + 1) / 2 << "\n";
	return 0;
}
