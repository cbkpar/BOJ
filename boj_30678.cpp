#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool matAns[3125][3125] = { false, };

void Divide(int iR, int iC, int iL)
{
	if (iL == 0)
	{
		matAns[iR][iC] = true;
	}
	else
	{
		Divide(iR - iL * 2, iC, iL / 5);
		Divide(iR - iL * 1, iC, iL / 5);
		Divide(iR, iC - iL * 2, iL / 5);
		Divide(iR, iC - iL * 1, iL / 5);
		Divide(iR, iC, iL / 5);
		Divide(iR, iC + iL * 1, iL / 5);
		Divide(iR, iC + iL * 2, iL / 5);
		Divide(iR + iL * 1, iC - iL * 1, iL / 5);
		Divide(iR + iL * 1, iC, iL / 5);
		Divide(iR + iL * 1, iC + iL * 1, iL / 5);
		Divide(iR + iL * 2, iC - iL * 1, iL / 5);
		Divide(iR + iL * 2, iC + iL * 1, iL / 5);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iLen = 1;
	for (int i = 0;i < iN;++i)
	{
		iLen *= 5;
	}

	int iMid = iLen / 2;
	Divide(iMid, iMid, iLen / 5);

	for (int i = 0;i < iLen;++i)
	{
		for (int j = 0;j < iLen;++j)
		{
			if (matAns[i][j])
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
