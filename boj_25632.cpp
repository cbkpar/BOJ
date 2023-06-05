#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ArrPrime[1001] = { false, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i * i <= 1000; i++) {
		for (int j = i * i; j <= 1000; j += i) {
			ArrPrime[j] = true;
		}
	}

	int iA, iB;
	cin >> iA >> iB;
	int iC, iD;
	cin >> iC >> iD;

	int iCountYT = 0;
	int iCountYJ = 0;
	int iCountUnion = 0;

	for (int i = iA; i <= iB; ++i)
	{
		if (!ArrPrime[i])
		{
			if (i >= iC && i <= iD)
			{
				++iCountUnion;
			}
			else
			{
				++iCountYT;
			}
		}
	}
	for (int i = iC; i <= iD; ++i)
	{
		if (!ArrPrime[i])
		{
			if (i >= iA && i <= iB)
			{
				++iCountUnion;
			}
			else
			{
				++iCountYJ;
			}
		}
	}
	if ((iCountUnion / 2) % 2 == 1) ++iCountYT;
	if (iCountYT > iCountYJ)
	{
		cout << "yt\n";
	}
	else
	{
		cout << "yj\n";
	}
	return 0;
}
