#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iX, iY;
	cin >> iN >> iX >> iY;

	for (int i = 0;i < iN;++i)
	{
		int iA;
		cin >> iA;

		cout << (iY * iA / iX) << "\n";
	}
	return 0;
}
