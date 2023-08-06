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
	--iN;

	int iRow = iN / 8;
	int iCol = iN % 8;

	cout << (char)(iCol + 'a');
	cout << (char)(iRow + '1');
	cout << "\n";
	return 0;
}
