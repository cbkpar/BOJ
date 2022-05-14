#include <iostream>

using namespace std;

int main()
{
	int iN, iK, iX, iY;
	cin >> iN >> iK >> iX >> iY;
	
	auto CalcDistSquare = [&](int _iX, int _iY)->int {
		if ((iX - _iX) * (iX - _iX) + (iY - _iY) * (iY - _iY) > iK * iK)
		{
			return 1;
		}
		return 0;
	};
	
	int iAnswer = 0;
	while (iN--)
	{
		int iX2, iY2;
		cin >> iX2 >> iY2;
		iAnswer += CalcDistSquare(iX2, iY2);
	}
	cout << iAnswer << endl;
	
	return 0;
}
