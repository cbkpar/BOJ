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

	cout << "YES" << "\n";
	if (iN % 4 == 2)
	{
		for (int i = 1; i <= iN; ++i)
		{
			if (i % 4 == 1) cout << (i + 1);
			if (i % 4 == 2) cout << (i - 1);
			if (i % 4 == 3) cout << i;
			if (i % 4 == 0) cout << i;
			cout << (i == iN ? "\n" : " ");
		}
	}
	else
	{
		for (int i = 1; i <= iN; ++i)
		{
			if (i % 4 == 1) cout << i;
			if (i % 4 == 2) cout << (i + 1);
			if (i % 4 == 3) cout << (i - 1);
			if (i % 4 == 0) cout << i;
			cout << (i == iN ? "\n" : " ");
		}
	}

	return 0;
}
