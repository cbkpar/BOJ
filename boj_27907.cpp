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

	for (int i = 0; i < iN; ++i)
	{
		cout << "2" << (i == iN - 1 ? "\n" : " ");
	}
	return 0;
}
