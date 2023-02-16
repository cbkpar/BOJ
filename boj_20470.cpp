#include <iostream>
#include <vector>

using namespace std;

int gcd(int iA, int iB)
{
	if (iB % iA == 0) return iA;
	return gcd(iB % iA, iA);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	int iGCD = -1;

	vector<int> vecNumber;
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;
		if (iNum % iK == 0)
		{
			if (vecNumber.size() == 0)
			{
				iGCD = iNum;
			}
			else
			{
				iGCD = (iGCD < iNum ? gcd(iGCD, iNum) : gcd(iNum, iGCD));
			}
			vecNumber.emplace_back(iNum);
		}
	}

	if (vecNumber.size() == 0 || iGCD != iK)
	{
		cout << "-1\n";
	}
	else
	{
		int iSize = vecNumber.size();
		cout << iSize << "\n";
		for (int i = 0; i < iSize; ++i)
		{
			cout << vecNumber[i] << (i == iSize - 1 ? "\n" : " ");
		}
	}
	return 0;
}
