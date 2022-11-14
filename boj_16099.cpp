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
		long long lWidth1, lHeight1, lWidth2, lHeight2;
		cin >> lWidth1 >> lHeight1 >> lWidth2 >> lHeight2;
		if (lWidth1 * lHeight1 > lWidth2 * lHeight2)
		{
			cout << "TelecomParisTech\n";
		}
		else if (lWidth1 * lHeight1 == lWidth2 * lHeight2)
		{
			cout << "Tie\n";
		}
		else
		{
			cout << "Eurecom\n";
		}
	}

	return 0;
}
