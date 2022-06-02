#include <iostream>

using namespace std;

int main()
{
	int iN, iM;
	cin >> iN >> iM;
    if ((iN <= iM && 0 == iN % 2) || (iN >= iM && 0 == iM % 2))
	{
		if (iN < iM)
		{
			cout << (iN / 2 - 1) << " " << (iN / 2) << endl;
		}
		else
		{
			cout << (iM / 2 - 1) << " " << (iM / 2) << endl;
		}
	}
	else
	{
		if (iN < iM)
		{
			cout << (iN / 2) << " " << (iN / 2) + (iM - iN) << endl;
		}
		else
		{
			cout << (iM / 2) + (iN - iM) << " " << (iM / 2) << endl;
		}
    }
	return 0;
}
