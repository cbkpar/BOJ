#include <iostream>

#define Max(a,b) (a>b)?a:b;

using namespace std;

int arrPresum[1000001];
bool bIsOdd[1000001];

int main()
{
	int iN;
	int iK;
	cin >> iN >> iK;
	for (int i = 1; i <= iN; ++i)
	{
		int iNumber;
		cin >> iNumber;
		arrPresum[i] = arrPresum[i - 1];
		if (0 != iNumber % 2)
		{
			++arrPresum[i];
			bIsOdd[i] = true;
		}
	}
	int iAnswer = 0;
	int iLeft = 0;
	int iRight = 1;
	while (iRight <= iN&&iLeft <= iRight)
	{
		iAnswer = Max(iAnswer, (iRight - iLeft) - (arrPresum[iRight] - arrPresum[iLeft]));
		if ((arrPresum[iRight] - arrPresum[iLeft]) <= iK)
		{
			++iRight;
		}
		else
		{
			++iLeft;
			++iRight;
		}
	}
	cout << (iAnswer) << endl;
	return 0;
}
