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

	if (iN <= 100000 && iN % 2024 == 0)
	{
		cout << "Yes" << "\n";
	}
	else
	{
		cout << "No" << "\n";
	}
	return 0;
}
