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

	double dR;
	cin >> dR;

	double dAns = dR * (3.14159265358979 / 2 - 1);
	
	cout.precision(30);
	cout << fixed;
	cout << dAns << "\n";

	return 0;
}
