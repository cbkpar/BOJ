#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN;
		cin >> iN;
		while (iN > 5)
		{
			cout << "++++ ";
			iN -= 5;
		}
		if (iN == 1)
		{
			cout << "|";
		}
		if (iN == 2)
		{
			cout << "||";

		}
		if (iN == 3)
		{
			cout << "|||";

		}
		if (iN == 4)
		{
			cout << "||||";

		}
		if (iN == 5)
		{
			cout << "++++";
		}
		cout << "\n";
	}
	return 0;
}
