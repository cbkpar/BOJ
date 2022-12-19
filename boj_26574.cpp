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
		int iNumber;
		cin >> iNumber;
		cout << iNumber << " " << iNumber << "\n";
	}
	return 0;
}
