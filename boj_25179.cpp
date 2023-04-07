#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long lN, lM;
	cin >> lN >> lM;

	if ((lN - 1) % (lM + 1) == 0)
	{
		cout << "Can't win\n";
	}
	else
	{
		cout << "Can win\n";
	}
	return 0;
}
