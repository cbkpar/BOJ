#include <iostream>
#include <set>

using namespace std;

bool bMap[1024][1024] = { false, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	bMap[0][0] = true;
	int iDist = 1;
	for (int i = 1; i <= iN; ++i)
	{
		for (int j = iDist; j < iDist * 2; ++j)
		{
			for (int k = 0; k < iDist; ++k)
			{
				if (bMap[j - iDist][k])
				{
					bMap[j][k] = true;
					bMap[j][k + iDist] = true;
				}
			}
		}
		iDist *= 2;
	}
	for (int i = iDist - 1; i >= 0; --i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (bMap[i][j])
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
