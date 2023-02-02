#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB;
	cin >> iA >> iB;
	if (iA < iB)
	{
		cout << "-1\n";
	}
	else if (iA == iB)
	{
		cout << "0\n";
	}
	else
	{
		cout << "1\n";
	}
	return 0;
}
