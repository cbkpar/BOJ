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

	bool bPossible = false;
	for (int i = 2;i <= 9;++i)
	{
		for (int j = 1;j <= 9;++j)
		{
			if (iN == i) bPossible = true;
			if (iN == j) bPossible = true;
			if (iN == i * j) bPossible = true;
		}
	}

	cout << (bPossible ? "1" : "0") << "\n";
	return 0;
}
