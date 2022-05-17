#include <iostream>

using namespace std;

int main()
{
	int iNumber;
	cin >> iNumber;
	int iAnswer = 0;
	int iPow = 1;
	while (iNumber)
	{
		int iTemp = iNumber % 10;
		if (iTemp > 4) 
		{
			--iTemp;
		}
		iAnswer += iTemp * iPow;
		iPow *= 9;
		iNumber /= 10;
	}
	cout << iAnswer << endl;
    return 0;
}
