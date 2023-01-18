#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	while (iN--)
	{
		int iNumber;
		cin >> iNumber;

		int iCount = 0;
		
		for (int i = 9; i >= 2; --i)
		{
			while (iNumber % i == 0)
			{
				iNumber /= i;
				++iCount;
			}
		}
		if (iNumber == 1)
		{
			if (iCount == 0)
			{
				++iCount;
			}
			cout << iCount << "\n";
		}
		else
		{
			cout << "-1\n";
		}
	}
	return 0;
}
