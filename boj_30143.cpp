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
		int iN, iA, iD;
		cin >> iN >> iA >> iD;

		int iSum = 0;
		for (int i = 1; i <= iN; ++i)
		{
			iSum += iA + iD * (i - 1);
		}
		cout << iSum << "\n";
	}
	return 0;
}
