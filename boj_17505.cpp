#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN, lK;
	cin >> lN >> lK;

	for (long long i = lN; i >= 1; --i)
	{
		if (i - 1 <= lK)
		{
			lK -= i - 1;
			cout << i << (i == 1 ? "\n" : " ");
			--lN;
		}
		else
		{
			if (lK == 0)
			{
				for (long long j = 1; j <= lN; ++j)
				{
					cout << j << (j == lN ? "\n" : " ");
				}
				break;
			}
			for (long long j = 1; j <= lN; ++j)
			{
				cout << j << " ";
				++lK;
				if (lK == i - 1)
				{
					cout << i << " ";
					for (long long k = j + 1; k < lN; ++k)
					{
						cout << k << (k == lN - 1 ? "\n" : " ");
					}
					break;
				}
			}

			break;
		}
	}
	return 0;
}
