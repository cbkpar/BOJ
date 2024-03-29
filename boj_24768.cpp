#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iA, iB;
		cin >> iA >> iB;
		if (iA == 0 && iB == 0) break;
		if (iA + iB == 13)
		{
			cout << "Never speak again." << "\n";

		}
		else if (iA > iB)
		{
			cout << "To the convention." << "\n";
		}
		else if (iB > iA)
		{
			cout << "Left beehind." << "\n";
		}
		else
		{
			cout << "Undecided." << "\n";
		}
	}
	return 0;
}
