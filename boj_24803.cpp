#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iG, iS, iC;
	cin >> iG >> iS >> iC;

	int iScore = 3 * iG + 2 * iS + iC;
	if (iScore >= 8)
	{
		cout << "Province or ";
	}
	else if (iScore >= 5)
	{
		cout << "Duchy or ";
	}
	else if (iScore >= 2)
	{
		cout << "Estate or ";
	}
	if (iScore >= 6)
	{
		cout << "Gold\n";
	}
	else if (iScore >= 3)
	{
		cout << "Silver\n";
	}
	else
	{
		cout << "Copper\n";
	}

	return 0;
}
