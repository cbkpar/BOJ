#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iC, iP;
	cin >> iN >> iC >> iP;
	if (iN <= iC * iP)
	{
		cout << "yes" << "\n";
	}
	else
	{
		cout << "no" << "\n";
	}

	return 0;
}
