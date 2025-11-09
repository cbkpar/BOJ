#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool bPossible = true;
	int iN;
	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;
		if (iNum < 48)
		{
			bPossible = false;
		}
	}

	cout << (bPossible ? "True" : "False") << "\n";
	return 0;
}
