#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int iN;
	cin >> iN;
	int iMax = 0;
	int iMin = 1000000001;
	int iNumber;
	int iAnswer = 0;
	for (int i = 0; i < iN; ++i)
	{
		cin >> iNumber;
		if (iAnswer < iNumber - iMin)
		{
			iAnswer = iNumber - iMin;
		}
		if (0 == i)
		{
			cout << "0";
		}
		else
		{
			cout << " " << iAnswer;
		}
		if (iMax < iNumber)
		{
			iMax = iNumber;
		}
		if (iMin > iNumber)
		{
			iMin = iNumber;
		}
	}
	cout << endl;
	return 0;
}
