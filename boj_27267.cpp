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

	int iAreaM = iA * iB;
	int iAreaP = iC * iD;

	if (iAreaM > iAreaP)
	{
		cout << "M" << "\n";
	}
	else if (iAreaM < iAreaP)
	{
		cout << "P" << "\n";
	}
	else
	{
		cout << "E" << "\n";
	}
	return 0;
}
