#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iTotal = 0;

	int iN;
	cin >> iN;
	for (int i = 1;i <= iN;++i)
	{
		if (i % 2 == 1)
		{
			iTotal += 3;
		}
		else
		{
			iTotal -= 2;
		}
	}

	cout << iTotal << "\n";
	return 0;
}
