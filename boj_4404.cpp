#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

double CalcDist(const pair<double, double>& p1, const pair<double, double>& p2)
{
	double dx = p1.first - p2.first;
	double dy = p1.second - p2.second;
	return sqrt(dx * dx + dy * dy);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	pair<double, double> pGopherPos;
	pair<double, double> pDogPos;

	cin >> pGopherPos.first >> pGopherPos.second;
	cin >> pDogPos.first >> pDogPos.second;

	vector<pair<double, pair<double, double>>> vecAns;

	pair<double, double> pHolePos;
	while (cin >> pHolePos.first >> pHolePos.second)
	{
		double dDistGopher = CalcDist(pHolePos, pGopherPos);
		double dDistDog = CalcDist(pHolePos, pDogPos);

		if (dDistGopher * 2 <= dDistDog)
		{
			vecAns.push_back({ dDistGopher,pHolePos });
		}
	}
	if (vecAns.size() == 0)
	{
		cout << "The gopher cannot escape.\n";
		return 0;
	}

	sort(vecAns.begin(), vecAns.end());
	printf("The gopher can escape through the hole at (%.03f,%.03f).\n", vecAns[0].second.first, vecAns[0].second.second);
	return 0;
}
