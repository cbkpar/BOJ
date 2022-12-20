#include <iostream>

using namespace std;

int arrNumber[32] = { 0, };
int arrNumber2[32] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNumber;
	cin >> iNumber;
	for (int i = 0; i < 32; ++i)
	{
		if (iNumber % 2 == 1)
		{
			arrNumber[i] = 0;
			arrNumber2[i] = 1;
		}
		else
		{
			arrNumber[i] = 1;
		}
		iNumber /= 2;
	}
	++arrNumber[0];
	for (int i = 0; i < 31; ++i)
	{
		if (arrNumber[i] >= 2)
		{
			arrNumber[i] -= 2;
			arrNumber[i + 1] += 1;
		}
	}
	int iCount = 0;
	for (int i = 0; i < 32; ++i)
	{
		if (arrNumber[i] != arrNumber2[i])
		{
			++iCount;
		}
	}
	cout << iCount << "\n";
	return 0;
}
