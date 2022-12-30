#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	
	for (int i = 1; i <= iN; ++i)
	{
		if (i % 7 == 0 && i % 11 == 0)
		{
			cout << "Wiwat!\n";
		}
		else if (i % 7 != 0 && i % 11 == 0)
		{
			cout << "Super!\n";
		}
		else if (i % 7 == 0 && i % 11 != 0)
		{
			cout << "Hurra!\n";
		}
		else
		{
			cout << i << "\n";
		}
	}
	return 0;
}
