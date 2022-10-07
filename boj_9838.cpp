#include <iostream>
#include <memory.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	int* pArrNumber = new int[iN + 1];
	memset(pArrNumber, 0, sizeof(int) * (iN + 1));
	for (int i = 1; i <= iN; ++i)
	{
		int iNumber;
		cin >> iNumber;
		pArrNumber[iNumber] = i;
	}
	for (int i = 1; i <= iN; ++i)
	{
		cout << pArrNumber[i] << "\n";
	}
	delete[] pArrNumber;
	return 0;
}
