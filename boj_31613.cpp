#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iX, iN;
	cin >> iX >> iN;

	int iCount = 0;
	while (iX < iN)
	{
		if (iX % 3 == 0)
		{
			++iX;
		}
		else if (iX % 3 == 1)
		{
			iX *= 2;
		}
		else
		{
			iX *= 3;
		}
		++iCount;
	}

	cout << iCount << "\n";
	return 0;
}
