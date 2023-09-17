#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB;
	cin >> iA >> iB;

	if (iB >= iA)
	{
		cout << "NO" << "\n";
		return 0;
	}

	int iDiff = iA - iB;

	iA -= iDiff * 2;
	iB -= iDiff;
	if (iA < 0 || iB < 0 || iA != iB)
	{
		cout << "NO" << "\n";
		return 0;
	}

	cout << "YES" << "\n";
	cout << iDiff << "\n";
	for (int i = 0; i < iDiff - 1; ++i)
	{
		cout << "aba" << "\n";
	}
	cout << "aba";
	while (iA--)
	{
		cout << "ba";
	}
	cout << "\n";
	return 0;
}
