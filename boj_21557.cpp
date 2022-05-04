#include <iostream>

using namespace std;

int arr[200001];

int main()
{
	int iN;
	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		cin >> arr[i];
	}
	int iLeft = arr[0];
	int iRight = arr[iN - 1];
	while (iN-- > 3) {
		if (iLeft > iRight) {
			--iLeft;
		}
		else
		{
			--iRight;
		}
	}
	--iLeft;
	--iRight;
	cout << (iLeft > iRight ? iLeft : iRight) << endl;
	return 0;
}
