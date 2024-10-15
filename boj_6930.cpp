#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	for (int i = 2;i < iM;++i)
	{
		if ((iN * i) % iM == 1)
		{
			cout << i << "\n";
			return 0;
		}
	}

	cout << "No such integer exists." << "\n";
	return 0;
}
