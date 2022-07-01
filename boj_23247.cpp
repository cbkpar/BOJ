#include <iostream>

using namespace std;

int Mat[301][301] = { 0, };

int main()
{
	int iN, iM;
	cin >> iN >> iM;
	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 1; j <= iM; ++j)
		{
			cin >> Mat[i][j];
			Mat[i][j] += Mat[i - 1][j] + Mat[i][j - 1] - Mat[i - 1][j - 1];
		}
	}
	int iCount = 0;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			for (int k = i + 1; k <= iN; ++k)
			{
				for (int l = j + 1; l <= iM; ++l)
				{
					int iSum = Mat[k][l] - Mat[k][j] - Mat[i][l] + Mat[i][j];
					if (10 == iSum)
					{
						++iCount;
					}
                    if (10 <= iSum)
					{
						break;
					}
				}
			}
		}
	}
	cout << iCount << endl;
	return 0;
}
