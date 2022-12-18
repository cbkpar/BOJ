#include <iostream>
#include <map>

using namespace std;

int CalcNextNumber(int iNumber)
{
	while (true)
	{
		int iTemp = iNumber;
		while (iTemp > 0)
		{
			if (iTemp % 10 == 0)
			{
				break;
			}
			iTemp /= 10;
			if (iTemp == 0)
			{
				return iNumber;
			}
		}
		++iNumber;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	while (iN--)
	{
		int iNumber;
		cin >> iNumber;
		cout << CalcNextNumber(iNumber + 1) << "\n";
	}
	return 0;
}
