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
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;
		iAns = max(iAns, iNum - (iN - i));
	}
	cout << iAns << "\n";
	return 0;
}
