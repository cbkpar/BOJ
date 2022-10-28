#include <iostream>
#include <string>

using namespace std;

int matConnet[26][26] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	while (iN--)
	{
		string strA, strB, strC;
		cin >> strA >> strB >> strC;
		int iS = strA[0] - 'a';
		int iE = strC[0] - 'a';
		matConnet[iS][iE] = 1;
	}
	for (int k = 0; k < 26; ++k)
	{
		for (int i = 0; i < 26; ++i)
		{
			for (int j = 0; j < 26; ++j)
			{
				if (matConnet[i][k] == 1 && matConnet[k][j] == 1)
				{
					matConnet[i][j] = 1;
				}
			}
		}
	}
	int iM;
	cin >> iM;
	while (iM--)
	{
		string strA, strB, strC;
		cin >> strA >> strB >> strC;
		int iS = strA[0] - 'a';
		int iE = strC[0] - 'a';
		if (matConnet[iS][iE] == 1)
		{
			cout << "T\n";
		}
		else
		{
			cout << "F\n";
		}
	}
	return 0;
}
