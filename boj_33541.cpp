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

	for (int i = iN + 1;i <= 9999;++i)
	{
		int iA = i / 100;
		int iB = i % 100;
		if ((iA + iB) * (iA + iB) == i)
		{
			cout << i << "\n";
			return 0;
		}
	}

	cout << "-1" << "\n";
	return 0;
}
