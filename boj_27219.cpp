#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iDay;
	cin >> iDay;

	int iV = iDay / 5;
	int iI = iDay % 5;
	while (iV--)
	{
		cout << "V";
	}
	while (iI--)
	{
		cout << "I";
	}
	cout << "\n";
	return 0;
}
