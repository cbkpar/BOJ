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
		long long lN, lM;
		cin >> lN >> lM;
		if ((lN <= 2 || lM <= 2) || ((lN % 2) * (lM % 2)) == 1)
		{
			cout << "First" << "\n";
		}
		else
		{
			cout << "Second" << "\n";
		}
	}

	return 0;
}
