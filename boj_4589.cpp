#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int iN;
	cin >> iN;
	cout << "Gnomes:" << endl;
	while (iN--)
	{
		int iA, iB, iC;
		cin >> iA >> iB >> iC;
		if ((iA < iB && iB < iC) || (iA > iB && iB > iC))
		{
			cout << "Ordered" << endl;
		}
		else
		{
			cout << "Unordered" << endl;
		}
	}
	return 0;
}
