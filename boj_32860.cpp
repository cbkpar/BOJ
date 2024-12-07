#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	if (iK <= 26)
	{
		--iK;
		cout << "SN " << iN << (char)(iK + 'A') << "\n";
	}
	else
	{
		iK -= 27;
		cout << "SN " << iN << (char)(iK / 26 + 'a') << (char)(iK % 26 + 'a') << "\n";
	}
	return 0;
}
