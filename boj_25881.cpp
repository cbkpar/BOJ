#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iDefaultCost, iAccCost;
	cin >> iDefaultCost >> iAccCost;

	int iN;
	cin >> iN;

	while (iN--)
	{
		int iUsedEnergy;
		cin >> iUsedEnergy;
		cout << iUsedEnergy << " ";
		int iTotalCost = 0;
		if (iUsedEnergy > 1000)
		{
			iTotalCost += (iUsedEnergy - 1000) * iAccCost;
			iUsedEnergy = 1000;
		}
		iTotalCost += iUsedEnergy * iDefaultCost;
		cout << iTotalCost << "\n";
	}
	return 0;
}
