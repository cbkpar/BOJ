#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iS, iM;
	cin >> iS >> iM;

	if (iS <= 1023)
	{
		cout << "No thanks\n";
	}
	else
	{
		iS -= 1023;
		if ((iS & iM) == iS)
		{
			cout << "Thanks\n";
		}
		else
		{
			cout << "Impossible\n";
		}
	}
	return 0;
}
