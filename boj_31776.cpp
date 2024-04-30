#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iAns = 0;
	int iT;
	cin >> iT;
	while (iT--)
	{
		int iA, iB, iC;
		cin >> iA >> iB >> iC;

		if (iA != -1 && iB == -1 && iC == -1)
		{
			++iAns;
		}
		if (iA != -1 && iB != -1 && iC == -1)
		{
			if (iA <= iB)
			{
				++iAns;
			}
		}
		if (iA != -1 && iB != -1 && iC != -1)
		{
			if (iA <= iB && iB <= iC)
			{
				++iAns;
			}
		}
	}

	cout << iAns << "\n";
	return 0;
}
