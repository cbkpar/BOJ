#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iT;
	cin >> iT;

	while (iT-- > 0)
	{
		int iN;
		cin >> iN;
		for (int i = 0;i <= iN / 2;++i)
		{
			for (int j = 0;j < iN;++j)
			{
				if (j == 0 || j == iN - 1 || j == i || j == iN - 1 - i)
				{
					cout << "#";
				}
				else
				{
					cout << ".";
				}
			}
			cout << "\n";
		}
		for (int i = 0;i < iN / 2;++i)
		{
			for (int j = 0;j < iN;++j)
			{
				if (j == 0 || j == iN - 1)
				{
					cout << "#";
				}
				else
				{
					cout << ".";
				}
			}
			cout << "\n";
		}
	}

	return 0;
}
