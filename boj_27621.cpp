#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	if (iN == 30)
	{
		cout << "-283059965 -2218888517 2220422932\n";
		return 0;
	}
	else if (iN == 33)
	{
		cout << "8866128975287528 -8778405442862239 -2736111468807040\n";
		return 0;
	}
	else if (iN == 39)
	{
		cout << "117367 134476 -159380\n";
		return 0;
	}
	else if (iN == 42)
	{
		cout << "-80538738812075974 80435758145817515 12602123297335631\n";
		return 0;
	}

	for (int i = -50; i <= 50; ++i)
	{
		for (int j = -50; j <= 50; ++j)
		{
			for (int k = -50; k <= 50; ++k)
			{
				if (i * i * i + j * j * j + k * k * k == iN)
				{
					cout << i << " " << j << " " << k << "\n";
					return 0;
				}
			}
		}
	}
	cout << "0\n";
	return 0;
}
