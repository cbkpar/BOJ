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

	int iSum = 0;
	for (int i = 0;i < iN;++i)
	{
		int iGrade;
		cin >> iGrade;
		if (iGrade == 3)
		{
			cout << "None" << "\n";
			return 0;
		}
		iSum += iGrade;
	}

	if (iSum == iN * 5)
	{
		cout << "Named" << "\n";
	}
	else if (iSum * 2 >= 9 * iN)
	{
		cout << "High" << "\n";
	}
	else
	{
		cout << "Common" << "\n";
	}

	return 0;
}
