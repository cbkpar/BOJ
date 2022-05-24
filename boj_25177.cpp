#include <iostream>

using namespace std;

int arrA[1000] = { 0, };
int arrB[1000] = { 0, };
int main()
{
	int iN, iM;
	cin >> iN >> iM;
	for (int i = 0; i < iN; ++i)
	{
		cin >> arrA[i];
	}
	for (int i = 0; i < iM; ++i)
	{
		cin >> arrB[i];
	}
	int iMax = 0;
	for (int i = 0; i < 1000; ++i)
	{
		if (arrB[i] - arrA[i] > iMax)
		{
			iMax = arrB[i] - arrA[i];
		}
	}
	cout << iMax << endl;
	return 0;
}
