#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iM, iK;
	cin >> iM >> iK;

	if (iM % iK == 0)
	{
		cout << "Yes" << "\n";
	}
	else
	{
		cout << "No" << "\n";
	}

	return 0;
}
