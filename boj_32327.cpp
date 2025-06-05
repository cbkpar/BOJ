#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lSize = 0;
	cin >> lSize;

	long long lDusa;
	while (cin >> lDusa)
	{
		if (lSize > lDusa)
		{
			lSize += lDusa;
		}
		else
		{
			break;
		}
	}

	cout << lSize << "\n";
	return 0;
}
