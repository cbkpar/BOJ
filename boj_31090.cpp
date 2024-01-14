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
		int iYear;
		cin >> iYear;
		int iMod = iYear % 100;
		if ((iYear + 1) % iMod == 0)
		{
			cout << "Good" << "\n";
		}
		else
		{
			cout << "Bye" << "\n";
		}
	}

	return 0;
}
