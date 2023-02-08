#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	if (iN % 10 == iN / 10)
	{
		cout << "1\n";
	}
	else
	{
		cout << "0\n";
	}
	return 0;
}
