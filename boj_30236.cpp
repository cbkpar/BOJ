#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN;
		cin >> iN;

		int iNow = 0;

		for (int i = 1; i <= iN; ++i)
		{
			int iNum;
			cin >> iNum;
			++iNow;
			if (iNow == iNum) ++iNow;
		}
		cout << iNow << "\n";
	}

	return 0;
}
