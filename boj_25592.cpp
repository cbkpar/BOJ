#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iStage = 1;
	bool bPuang = true;
	while (true)
	{
		if (bPuang)
		{
			if (iN > iStage)
			{
				iN -= iStage;
			}
			else if (iN == iStage)
			{
				cout << "0\n";
				return 0;
			}
			else
			{
				cout << (iStage - iN) << "\n";
				return 0;
			}
		}
		else
		{

			if (iN > iStage)
			{
				iN -= iStage;
			}
			else if (iN == iStage)
			{
				cout << (iStage + 1) << "\n";
				return 0;
			}
			else
			{
				cout << "0\n";
				return 0;
			}
		}
		++iStage;
		bPuang = !bPuang;
	}
	return 0;
}
