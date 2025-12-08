#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT-- > 0)
	{
		int iN, iM;
		cin >> iN >> iM;

		cout << (iN + iM - 1) << "\n";
	}

	return 0;

}
