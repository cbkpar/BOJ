#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB, iC;
	cin >> iA >> iB >> iC;
	if (iA + iB == iC)
	{
		cout << "correct!" << "\n";
	}
	else
	{
		cout << "wrong!" << "\n";
	}

	return 0;
}
