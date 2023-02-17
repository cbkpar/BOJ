#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		vector<double> vecUnit(3);
		cin >> vecUnit[0] >> vecUnit[1] >> vecUnit[2];
		if (vecUnit[0] == 0 && vecUnit[1] == 0 && vecUnit[2] == 0) break;

		sort(vecUnit.begin(), vecUnit.end(), greater<>());

		if (vecUnit[0] >= 125 && vecUnit[0] <= 290 && vecUnit[1] >= 90 && vecUnit[1] <= 155 && vecUnit[2] >= 0.25 && vecUnit[2] <= 7)
		{
			cout << "letter\n";
		}
		else if (vecUnit[0] >= 125 && vecUnit[0] <= 380 && vecUnit[1] >= 90 && vecUnit[1] <= 300 && vecUnit[2] >= 0.25 && vecUnit[2] <= 50)
		{
			cout << "packet\n";
		}
		else if ((vecUnit[0] >= 125 && vecUnit[1] >= 90 && vecUnit[2] >= 0.25) && (vecUnit[0] + vecUnit[1] * 2 + vecUnit[2] * 2) <= 2100)
		{
			cout << "parcel\n";
		}
		else
		{
			cout << "not mailable\n";
		}
	}
	return 0;
}
