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

	for (int i = 0;i < iN;++i)
	{
		int iTime;
		cin >> iTime;
		if ((iTime % 25) < 17)
		{
			cout << "ONLINE" << "\n";
		}
		else
		{
			cout << "OFFLINE" << "\n";
		}
	}

	return 0;
}
