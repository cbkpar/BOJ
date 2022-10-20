#include <iostream>
#include <memory.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;

	for (int i = 1; i <= iT; ++i)
	{
		int iN;
		cin >> iN;
		int* arrNumber = new int[iN * 2];
		for (int j = 0; j < 2 * iN; ++j)
		{
			cin >> arrNumber[j];
		}
		cout << "Case #" << i << ":";
		for (int j = 0; j < 2 * iN; ++j)
		{
			if (arrNumber[j] != 0)
			{
				for (int k = j + 1; k < 2 * iN; ++k)
				{
					if (arrNumber[k] / 4 == arrNumber[j] / 3)
					{
						arrNumber[k] = 0;
						cout << " " << arrNumber[j];
						break;
					}
				}
			}
		}
		cout << "\n";
	}
	return 0;
}
