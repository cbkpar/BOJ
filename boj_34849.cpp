#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	if (iN <= 10000)
	{
		cout << "Accepted" << "\n";
	}
	else
	{
		cout << "Time limit exceeded" << "\n";
	}

	return 0;

}
