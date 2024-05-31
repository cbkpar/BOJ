#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while(iT--)
	{
		long long lX;
		cin >> lX;
		cout << (lX*2-1) << "\n";
	}

	return 0;
}
