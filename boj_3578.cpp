#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	if (iN == 0)
	{
		cout << "1\n";
		return 0;
	}
	else if (iN == 1)
	{
		cout << "0\n";
		return 0;
	}
	if (iN % 2 == 1)
	{
		cout << "4";
	}
	while (iN >= 2)
	{
		iN -= 2;
		cout << "8";
	}
	cout << "\n";
	return 0;
}
