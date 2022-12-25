#include <iostream>

using namespace std;

int arrPower[50002] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	for (int i = 1; i <= iN; ++i)
	{
		cin >> arrPower[i];
	}
	for (int i = 1; i <= iN; ++i)
	{
		if (arrPower[i] >= arrPower[i - 1] && arrPower[i] >= arrPower[i + 1])
		{
			cout << i << "\n";
		}
	}

	return 0;
}
