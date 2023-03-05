#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long long lN;
	cin >> lN;

	for (int i = 0; i < 5; ++i)
	{
		long long lCount = lN - (long long)i * 3;
		if (lCount >= 0 && lCount % 5 == 0)
		{
			cout << ((lCount / 5) + i) << "\n";
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}
