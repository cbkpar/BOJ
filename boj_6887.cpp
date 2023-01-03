#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iSqrt = int(sqrt(iN));
	cout << "The largest square has side length " << iSqrt << ".\n";

	return 0;
}
