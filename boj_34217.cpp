#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB, iC, iD;
	cin >> iA >> iB >> iC >> iD;

	if (iA + iC < iB + iD)
	{
		cout << "Hanyang Univ." << "\n";
	}
	else if (iA + iC == iB + iD)
	{
		cout << "Either" << "\n";
	}
	else
	{
		cout << "Yongdap" << "\n";
	}

	return 0;
}
