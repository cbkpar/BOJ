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

	long long iA = 0;
	long long iB = 0;

	for (int i = 0;i < iN;++i)
	{
		long long iNum;
		cin >> iNum;

		if (i % 2 == 0)
		{
			iA += iNum;
		}
		else
		{
			iB += iNum;
		}
	}

	if (iN == 3)
	{
		if (iA <= iB)
		{
			cout << (iB - iA) << "\n";
		}
		else
		{
			cout << "-1" << "\n";
		}
	}
	else
	{
		cout << abs(iA - iB) << "\n";
	}

	return 0;
}
