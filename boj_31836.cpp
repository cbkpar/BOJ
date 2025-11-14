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

	if (iN % 3 == 0)
	{
		cout << (iN / 3) << "\n";
		for (int i = 0;i < iN / 3;++i)
		{
			cout << (i + 1) * 3 << (i == (iN / 3) - 1 ? "\n" : " ");
		}
		cout << ((iN / 3) * 2) << "\n";
		for (int i = 0;i < iN / 3;++i)
		{
			cout << ((i * 3) + 1) << " ";
			cout << ((i * 3) + 2) << (i == (iN / 3) * 2 - 1 ? "\n" : " ");
		}
	}
	else if (iN % 3 == 1)
	{
		cout << (iN / 3) << "\n";
		for (int i = 0;i < iN / 3;++i)
		{
			cout << (i + 1) * 3 + 1 << (i == (iN / 3) - 1 ? "\n" : " ");
		}
		cout << ((iN / 3) * 2) << "\n";
		for (int i = 0;i < iN / 3;++i)
		{
			cout << ((i * 3) + 2) << " ";
			cout << ((i * 3) + 3) << (i == (iN / 3) * 2 - 1 ? "\n" : " ");
		}
	}
	else
	{
		cout << (iN / 3) + 1 << "\n";
		cout << "1" << (iN == 2 ? "\n" : " ");
		for (int i = 0;i < iN / 3;++i)
		{
			cout << (i + 1) * 3 + 2 << (i == (iN / 3) - 1 ? "\n" : " ");
		}
		cout << ((iN / 3) * 2) + 1 << "\n";
		cout << "2" << (iN == 2 ? "\n" : " ");
		for (int i = 0;i < iN / 3;++i)
		{
			cout << ((i * 3) + 3) << " ";
			cout << ((i * 3) + 4) << (i == (iN / 3) * 2 - 1 ? "\n" : " ");
		}
	}


	return 0;
}
