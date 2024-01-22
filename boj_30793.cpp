#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lP, lX;
	cin >> lP >> lX;

	long long lCalc = (lP * 100) / lX;

	if (lCalc < 20)
	{
		cout << "weak" << "\n";
	}
	else if (lCalc < 40)
	{
		cout << "normal" << "\n";
	}
	else if (lCalc < 60)
	{
		cout << "strong" << "\n";
	}
	else
	{
		cout << "very strong" << "\n";
	}

	return 0;
}
