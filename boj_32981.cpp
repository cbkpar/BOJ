#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iQ;
	cin >> iQ;
	while (iQ-- > 0)
	{
		int iN;
		cin >> iN;
		if (iN == 1)
		{
			cout << "5" << "\n";
		}
		else
		{
			long long lAns = 4;
			--iN;
			long long lPow = 5;
			while (iN > 0)
			{
				if (iN % 2 == 1)
				{
					lAns = (lAns * lPow) % 1000000007L;
				}
				lPow = (lPow * lPow) % 1000000007L;
				iN >>= 1;
			}
			cout << lAns << "\n";
		}
	}

	return 0;
}
