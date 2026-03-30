#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN;
	cin >> iN;
	cout << (iN - 1) * 2 << " ";
	cout << ((iN - 1) * 2 - 1) << "\n";
	return 0;
}
