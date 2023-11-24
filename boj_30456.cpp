#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iP;
	cin >> iN >> iP;

	for (int i = 0; i < iP - 1; ++i)
	{
		cout << "1";
	}
	cout << iN << "\n";
	return 0;
}
