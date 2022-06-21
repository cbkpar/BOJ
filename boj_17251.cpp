#include <iostream>

using namespace std;

int arrPower[1000000];
int arrLMaxPower[1000000];
int arrRMaxPower[1000000];
int main()
{
	int iN;
	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		cin >> arrPower[i];
	}
	arrLMaxPower[0] = arrPower[0];
	for (int i = 1; i < iN; ++i)
	{
		arrLMaxPower[i] = arrLMaxPower[i - 1] > arrPower[i] ? arrLMaxPower[i - 1] : arrPower[i];
	}
	arrRMaxPower[iN - 1] = arrPower[iN - 1];
	for (int i = iN - 2; i >= 0; --i)
	{
		arrRMaxPower[i] = arrRMaxPower[i + 1] > arrPower[i] ? arrRMaxPower[i + 1] : arrPower[i];
	}
	int iRCount = 0;
	int iBCount = 0;
	for (int i = 0; i < iN - 1; ++i)
	{
		if (arrLMaxPower[i] < arrRMaxPower[i + 1])
		{
			++iBCount;
		}
		else if (arrLMaxPower[i] > arrRMaxPower[i + 1])
		{
			++iRCount;
		}
	}
	if (iRCount > iBCount)
	{
		cout << "R" << endl;
	}
	else if (iRCount < iBCount)
	{
		cout << "B" << endl;
	}
	else
	{
		cout << "X" << endl;
	}
	return 0;
}
