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

	int iEven = 0;
	int iOdd = 0;

	while (iN--)
	{
		int iNum;
		cin >> iNum;

		if (iNum % 2 == 0)
		{
			++iEven;
		}
		else
		{
			++iOdd;
		}
	}

	if (iEven > iOdd)
	{
		cout << "Happy" << "\n";
	}
	else
	{
		cout << "Sad" << "\n";
	}

	return 0;
}
