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
		int iN;
		cin >> iN;

		cout << "YES" << "\n";
		for (int i = 1; i <= iN; ++i)
		{
			cout << i << (i == iN ? "\n" : " ");
		}
	}

	return 0;
}
