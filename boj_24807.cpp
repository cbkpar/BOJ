#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB, iC, iL;
	cin >> iA >> iB >> iC >> iL;

	bool bPossible = false;

	for (int a = 0;a <= iL / iA;++a)
	{
		for (int b = 0;b <= iL / iB;++b)
		{
			for (int c = 0;c <= iL / iC;++c)
			{
				if (a * iA + b * iB + c * iC == iL)
				{
					bPossible = true;
					cout << a << " " << b << " " << c << "\n";
				}
			}
		}
	}

	if (!bPossible)
	{
		cout << "impossible" << "\n";
	}
	return 0;
}
