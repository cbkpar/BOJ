#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iK;
	cin >> iK;

	if (iK % 2 == 0)
	{
		cout << "0" << "\n";
	}
	else
	{
		cout << "8" << "\n";
	}

	return 0;
}
