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
	for (int t = 1; t <= iT; ++t)
	{
		bool bMack = false;
		bool bZack = false;

		if (t > 1) cout << "\n";
		for (int i = 0; i < 10; ++i)
		{
			int iNum;
			cin >> iNum;
			cout << iNum << (i == 9 ? "\n" : " ");
			if (iNum == 17) bZack = true;
			if (iNum == 18) bMack = true;
		}
		if (bMack && bZack) cout << "both\n";
		if (!bMack && bZack) cout << "zack\n";
		if (bMack && !bZack) cout << "mack\n";
		if (!bMack && !bZack) cout << "none\n";

	}
	return 0;
}
