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

	int iAns = 6;
	for (int i = 11; i <= iN; ++i)
	{
		iAns *= i;
	}

	cout << iAns << "\n";
	return 0;
}
