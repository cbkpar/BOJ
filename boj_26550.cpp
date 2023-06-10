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

	while (iN--)
	{
		long long lNum;
		cin >> lNum;
		cout << (lNum) * (lNum + 1) * (lNum + 2) / 6 << "\n";
	}
	return 0;
}
