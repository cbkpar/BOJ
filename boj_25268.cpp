#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

char arrChar[10] = { 'b','c','d','f','g','h','j','k','l','m' };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	for (int i = 0;i < iN;++i)
	{
		int iTemp = i;
		for (int j = 0; j < 12;++j)
		{
			if (j % 3 == 0)
			{
				cout << 'a';
			}
			else
			{
				cout << arrChar[iTemp % 10];
				iTemp /= 10;
			}
		}
		cout << "\n";
	}

	return 0;
}
