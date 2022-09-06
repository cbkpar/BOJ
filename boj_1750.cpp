#include <iostream>

using namespace std;

int arrCount[100001] = { 0, };

int GCD(int iA, int iB)
{
	if (iB%iA == 0) return iA;
	return GCD(iB%iA, iA);
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
		for (int i = 1; i <= 100000; ++i)
		{
			if (arrCount[i] != 0)
			{
				int iGCD;
				if (iNumber > i)
				{
					iGCD = GCD(i, iNumber);
				}
				else
				{
					iGCD = GCD(iNumber, i);
				}
				arrCount[iGCD] = (arrCount[iGCD] + arrCount[i]) % 10000003;
			}
		}
		arrCount[iNumber] = (arrCount[iNumber] + 1) % 10000003;
	}
	cout << arrCount[1] << endl;
}
