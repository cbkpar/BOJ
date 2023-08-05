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
	while (iT--)
	{
		double dA, dB;
		cin >> dA >> dB;

		printf("The height of the triangle is %.02lf units\n",(dA/dB*2.0));
	}

	return 0;
}
