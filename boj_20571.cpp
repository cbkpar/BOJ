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

	string strBuilding;
	int iFloor;
	cin >> strBuilding >> iFloor;

	if (strBuilding == "residential")
	{
		cout << (iFloor + 4) / 5 << "\n";
	}
	if (strBuilding == "commercial")
	{
		if (iFloor >= 8) ++iFloor;
		cout << (iFloor + 5) / 7 << "\n";
	}
	if (strBuilding == "industrial")
	{
		if (iFloor == 1) --iFloor;
		cout << (iFloor + 3) / 4 << "\n";
	}
	return 0;
}
