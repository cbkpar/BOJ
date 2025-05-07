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

	for (int i = 1;i <= iN;++i)
	{
		if (i % 2 == 0)
		{
			cout << (i / 2);
		}
		else
		{
			cout << (iN-(i / 2));
		}
		cout << (i == iN ? "\n" : " ");
	}

	return 0;
}
