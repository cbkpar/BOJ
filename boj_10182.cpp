#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		string strpH, equal;
		double dH;
		cin >> strpH >> equal >> dH;

		double dpH = -log10(dH);
		if (strpH == "OH") dpH = 14 - dpH;
		cout << fixed;
		cout.precision(2);
		cout << dpH << "\n";
	}
	return 0;
}
