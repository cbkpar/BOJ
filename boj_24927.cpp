#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	int iCount = 0;

	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;
		
		while (iNum > 0 && iNum % 2 == 0)
		{
			iNum /= 2;
			++iCount;
		}
	}

	if (iCount >= iK)
	{
		cout << "1" << "\n";
	}
	else
	{
		cout << "0" << "\n";
	}

	return 0;
}
