#include <iostream>

using namespace std;

int main()
{
	int ArrPrize[25] = {
		100,200,400,800,1600,
		3200,6400,13000,26000,52000,
		104000,208000,416000,832000,1670000,
		3340000,6680000,13360000,26720000,53440000,
		106900000,213800000,427600000,855200000,1710400000
	};
	int iInput;
	cin >> iInput;
	for (int i = 0; i < iInput; ++i)
	{
		cout << ArrPrize[i] << endl;
	}
	return 0;
}
