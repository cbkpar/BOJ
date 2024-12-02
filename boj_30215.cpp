#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iO, iA, iB;
	cin >> iO >> iA >> iB;

	bool bPossible = false;
	for (int i = 1; i <= 150; ++i)
	{
		for (int j = 1; j <= 150; ++j)
		{
			if (iO == iA * i + iB * j)
			{
				bPossible = true;
			}
		}
	}

	cout << (bPossible ? "1" : "0") << "\n";
	return 0;
}
