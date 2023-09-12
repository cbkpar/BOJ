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

	int iThree = 0;
	int iTwo = 0;

	while (true)
	{
		if (iN % 3 == 0) break;
		iN -= 2;
		++iTwo;
	}
	iThree += iN / 3;
	cout << iTwo << " " << iThree << "\n";
	return 0;
}
