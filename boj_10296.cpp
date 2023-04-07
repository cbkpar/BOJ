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
	while (iT--)
	{
		int iG, iK;
		cin >> iG >> iK;

		iG -= 100;
		if (iG <= 0)
		{
			cout << "0\n";
			continue;
		}
		iG += (iK * 100 - 91);
		cout << (iG / (iK * 100 - 90)) << "\n";
	}
	return 0;
}
