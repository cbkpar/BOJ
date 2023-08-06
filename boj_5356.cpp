#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 0; t < iT; ++t)
	{
		if (t > 0) cout << "\n";

		int iN;
		char ch;
		cin >> iN >> ch;

		for (int i = 0; i < iN; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				cout << (char)((ch - 'A' + i) % 26 + 'A');
			}
			cout << "\n";
		}
	}
	return 0;
}
