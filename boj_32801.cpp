#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iA, iB;
	cin >> iN >> iA >> iB;

	int iFizz = 0;
	int iBuzz = 0;
	int iFizzBuzz = 0;


	for (int i = 1;i <= iN;++i)
	{
		if (i % iA == 0 && i % iB == 0)
		{
			++iFizzBuzz;
		}
		else if (i % iA == 0)
		{
			++iFizz;
		}
		else if (i % iB == 0)
		{
			++iBuzz;
		}
	}
	cout << iFizz << " " << iBuzz << " " << iFizzBuzz << "\n";
	return 0;
}
