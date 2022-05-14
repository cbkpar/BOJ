#include <iostream>

using namespace std;

int main()
{
	int iN;
	cin >> iN;
	while (iN--) 
	{
		long long llN;
		cin >> llN;
		if ([=]()->bool {
			for (int i = 2; i <= 1000000; ++i)
			{
				if (0 == llN % i)
				{
					return false;
				}
			}
			return true;
			}())
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
