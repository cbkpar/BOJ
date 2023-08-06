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

	int iSum = 0;

	int iN;
	cin >> iN;
	while (iN--)
	{
		string strWord;
		cin >> strWord;

		if (strWord == "Poblano") iSum += 1500;
		if (strWord == "Mirasol") iSum += 6000;
		if (strWord == "Serrano") iSum += 15500;
		if (strWord == "Cayenne") iSum += 40000;
		if (strWord == "Thai") iSum += 75000;
		if (strWord == "Habanero") iSum += 125000;
	}
	cout << iSum << "\n";
	return 0;
}
