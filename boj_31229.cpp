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
		cout << (1000000000 - i) << (i == iN ? "\n" : " ");
	}
	return 0;
}
