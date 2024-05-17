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

	int iX, iS;
	cin >> iX >> iS;

	bool bPossible = false;

	while (iN--)
	{
		int iC, iP;
		cin >> iC >> iP;

		if (iP > iS && iC <= iX)
		{
			bPossible = true;
		}
	}

	if (bPossible)
	{
		cout << "YES" << "\n";
	}
	else
	{
		cout << "NO" << "\n";
	}


	return 0;
}
