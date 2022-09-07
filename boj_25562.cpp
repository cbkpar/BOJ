#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	cout << (iN * (iN - 1) / 2) << "\n";
	for (int i = 0; i < iN; ++i)
	{
		cout << (1 << i) << (i + 1 == iN ? "\n" : " ");
	}
	cout << (iN - 1) << "\n";
	for (int i = 1; i <= iN; ++i)
	{
		cout << i << (i == iN ? "\n" : " ");
	}
}
