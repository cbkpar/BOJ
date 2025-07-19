#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB;
	cin >> iA >> iB;

	int iAns = 1;
	while (true)
	{
		if (iA > iB)
		{
			++iAns;
			iA -= iB;
		}
		else if (iB > iA)
		{
			++iAns;
			iB -= iA;
		}
		if (iA == iB) break;
	}

	cout << iAns << "\n";
	return 0;
}
