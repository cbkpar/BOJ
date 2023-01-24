#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iIndex = 0;
	long long lUnit;

	while (true)
	{
		cin >> lUnit;
		if (lUnit == 0)
		{
			break;
		}

		int iN;
		cin >> iN;

		cout << "User " << (++iIndex) << "\n";
		while (iN--)
		{
			long long lLength;
			cin >> lLength;
			lLength *= lUnit;
			cout << (lLength / 100000) << ".";
			lLength %= 100000;
			for (int i = 10000; i >= 1; i /= 10)
			{
				cout << (lLength / i);
				lLength %= i;
			}
			cout << "\n";
		}
	}
	return 0;
}
