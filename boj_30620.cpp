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

	long long lA, lB;
	cin >> lA >> lB;

	long long lSum = lA * lB;
	cout << "2" << "\n";
	cout << (lSum - lA) << "\n";
	cout << (lB - lSum) << "\n";

	return 0;
}
