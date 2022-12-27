#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	while (iN--)
	{
		int iR, iC;
		cin >> iC >> iR;

		for (int i = 0; i < iR; ++i)
		{
			for (int j = 0; j < iC; ++j)
			{
				cout << "X";
			}
			cout << "\n";
		}

		if (iN >= 1) cout << "\n";
	}
	return 0;
}
