#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iH, iW, iA, iB;
	cin >> iH >> iW >> iA >> iB;

	if (iH * 2 >= iA && iW >= iB)
	{
		cout << "YES" << "\n";
		return 0;
	}

	if (iH * 2 >= iB && iW >= iA)
	{
		cout << "YES" << "\n";
		return 0;
	}
	cout << "NO" << "\n";
	return 0;
}
