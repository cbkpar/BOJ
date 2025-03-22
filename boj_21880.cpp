#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB;
	cin >> iA >> iB;

	if (iA > iB)
	{
		for (int i = 1; i <= iB; ++i)
		{
			cout << "0:" << i << "\n";
		}
		for (int i = 1; i <= iA; ++i)
		{
			cout << i << ":" << iB << "\n";
		}

	}
	else
	{
		for (int i = 1; i <= iA; ++i)
		{
			cout << i << ":0" << "\n";
		}
		for (int i = 1; i <= iB; ++i)
		{
			cout << iA << ":" << i << "\n";
		}
	}

	return 0;
}
