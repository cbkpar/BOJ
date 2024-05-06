#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double dAns = 1;
	double dNum = 1;

	int iN;
	cin >> iN;
	for (int i = 1; i <= iN; ++i)
	{
		dNum *= (double)(i);
		dAns += 1.0 / dNum;
	}

	cout.precision(30);
	cout << fixed;
	cout << dAns << "\n";
	return 0;
}
