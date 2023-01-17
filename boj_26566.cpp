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
		long long lA, lAP;
		cin >> lA >> lAP;
		long long lR, lRP;
		cin >> lR >> lRP;

		if (lA * lRP * 1000 > lR * lR * 3141 * lAP)
		{
			cout << "Slice of pizza\n";
		}
		else
		{
			cout << "Whole pizza\n";
		}
	}

	return 0;
}
