#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 1; t <= iT; ++t)
	{
		double dDist = 0;

		int iN;
		double dWeight;
		cin >> iN >> dWeight;
		vector<vector<double>> vecInfo(iN, vector<double>(3, 0));
		for (int i = 0; i < iN; ++i)
		{
			cin >> vecInfo[i][0];
			cin >> vecInfo[i][1];
			cin >> vecInfo[i][2];
			dWeight += vecInfo[i][0];
		}

		double dVelocity = 0;
		for (int i = 0; i < iN; ++i)
		{
			double dAccelation = vecInfo[i][2] / dWeight - 9.81;
			dDist += dVelocity * vecInfo[i][1] + 0.5 * dAccelation * vecInfo[i][1] * vecInfo[i][1];
			dVelocity += dAccelation * vecInfo[i][1];
			dWeight -= vecInfo[i][0];
		}
		if (t > 1) printf("\n");
		printf("Data Set %d:\n%.02f\n", t, dDist);
	}
	return 0;
}
