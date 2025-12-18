#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	while (iN-- > 0)
	{
		long long lTime;
		cin >> lTime;

		long long lA = 0;
		long long lB = 3;
		long long lCount = 1;
		while (true)
		{
			if (lTime > lA && lTime <= lB)
			{
				if (lTime > lA && lTime <= lA + lCount)
				{
					cout << lCount << " dolphin";
					if (lCount > 1) cout << "s";
					cout << "\n";
				}
				else if (lTime > lA + lCount && lTime <= lA + lCount * 2)
				{
					cout << lCount << " jump";
					if (lCount > 1) cout << "s";
					cout << "\n";
				}
				else
				{
					cout << "splash" << "\n";
				}
				break;
			}
			else
			{
				lA = lB;
				++lCount;
				lB += lCount * 3;
			}
		}
	}

	return 0;
}
