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
	bool bFirst = true;
	for (int i = 1; i <= iN; ++i)
	{
		if (!bFirst) cout << " ";
		bFirst = false;

		if (i % 15 == 0)
		{
			cout << "DeadMan\n";
			bFirst = true;
		}
		else if (i % 5 == 0)
		{
			cout << "Man\n";
			bFirst = true;
		}
		else if (i % 3 == 0)
		{
			cout << "Dead\n";
			bFirst = true;
		}
		else
		{
			cout << i;
		}
	}
	return 0;
}
