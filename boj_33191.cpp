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

	int iN;
	cin >> iN;

	int iA, iB, iC;
	cin >> iA >> iB >> iC;

	if (iA <= iN)
	{
		cout << "Watermelon" << "\n";
		return 0;
	}
	if (iB <= iN)
	{
		cout << "Pomegranates" << "\n";
		return 0;
	}
	if (iC <= iN)
	{
		cout << "Nuts" << "\n";
		return 0;
	}
	cout << "Nothing" << "\n";
	return 0;
}
