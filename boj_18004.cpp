#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB;
	cin >> iA >> iB;

	int iCount = 0;

	while (iA > iB)
	{
		++iCount;
		if (iA % 2 == 1)
		{
			++iA;
		}
		else
		{
			iA /= 2;
		}
	}
	iCount += iB - iA;

	cout << iCount << "\n";
	return 0;
}
