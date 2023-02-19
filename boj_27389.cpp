#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	cout << (iN / 4) << ".";
	switch (iN%4)
	{
	case 0: cout << "0"; break;
	case 1: cout << "25"; break;
	case 2: cout << "5"; break;
	case 3: cout << "75"; break;
	}

	cout << "\n";
	return 0;
}
