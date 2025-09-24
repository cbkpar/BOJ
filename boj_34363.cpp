#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double dS, dD, dT;
	cin >> dS >> dD >> dT;

	if(dS*5280*dT/3600 >= dD)
	{
		cout << "MADE IT" << "\n";
	}
	else
	{
		cout << "FAILED TEST" << "\n";
	}

	return 0;
}
