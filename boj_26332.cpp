#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iC, iP;
		cin >> iC >> iP;
		cout << iC << " " << iP << "\n";
		
		int iTotalCost = iP + (iP - 2) * (iC - 1);
		cout << iTotalCost << "\n";
	}

	return 0;
}
