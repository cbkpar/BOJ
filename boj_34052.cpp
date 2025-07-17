#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iSum = 0;
	for (int i = 0;i < 4;++i)
	{
		int iTime;
		cin >> iTime;
		iSum += iTime;
	}

	if (iSum + 300 <= 1800)
	{
		cout << "Yes" << "\n";
	}
	else
	{
		cout << "No" << "\n";
	}

	return 0;
}
