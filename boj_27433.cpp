#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lAnswer = 1;

	int iN;
	cin >> iN;

	for (int i = 2; i <= iN; ++i)
	{
		lAnswer *= i;
	}
	cout << lAnswer << "\n";
	return 0;
}
