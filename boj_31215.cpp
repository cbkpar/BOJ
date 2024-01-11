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
		int iN;
		cin >> iN;

		if (iN < 3)
		{
			cout << "1" << "\n";
		}
		else
		{
			cout << "3" << "\n";
		}
	}
	return 0;
}
