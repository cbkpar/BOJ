#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 1;t <= iT;++t)
	{
		int iR, iC;
		cin >> iR >> iC;

		cout << "Case #" << t << ":\n";
		for (int i = 0;i < iR * 2 + 1;++i)
		{
			for (int j = 0;j < iC * 2 + 1;++j)
			{
				if (i <= 1 && j <= 1)
				{
					cout << ".";
				}
				else
				{
					if (i % 2 == 0)
					{
						if (j % 2 == 0)
						{
							cout << "+";
						}
						else
						{
							cout << "-";
						}
					}
					else
					{
						if (j % 2 == 0)
						{
							cout << "|";
						}
						else
						{
							cout << ".";
						}
					}
				}
				if (j == iC * 2) cout << "\n";
			}
		}
	}

	return 0;
}
