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
		int iA, iB;
		cin >> iA >> iB;
		int iTemp;
		for (int i = 0; i < iA + iB; ++i) cin >> iTemp;

		if (iA <= iB)
		{
			cout << "Yes" << "\n";
		}
		else
		{
			cout << "No" << "\n";
		}
	}
	return 0;
}
