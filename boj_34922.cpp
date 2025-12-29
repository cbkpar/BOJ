#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	double dW, dH;
	cin >> dW >> dH;

	double dR;
	cin >> dR;

	double dArea = dW * dH - (dR * dR * 3.1415926535 / 4.0);

	std::cout.precision(30);
	std::cout << fixed;
	std::cout << dArea << "\n";
	return 0;
}
