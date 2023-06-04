#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 1; t <= iT; ++t)
	{
		int iN;
		string strCommand;
		cin >> iN >> strCommand;

		vector<vector<int>> matNum(iN, vector<int>(iN, 0));
		for (int i = 0; i < iN; ++i)
		{
			for (int j = 0; j < iN; ++j)
			{
				cin >> matNum[i][j];
			}
		}
		if (strCommand == "left")
		{
			for (int i = 0; i < iN; ++i)
			{
				for (int j = 0; j < iN; ++j)
				{
					if (matNum[i][j] == 0)
					{
						for (int k = j + 1; k < iN; ++k)
						{
							if (matNum[i][k] != 0)
							{
								swap(matNum[i][j], matNum[i][k]);
								break;
							}
						}
					}
					if (matNum[i][j] != 0)
					{
						for (int k = j + 1; k < iN; ++k)
						{
							if (matNum[i][k] != 0)
							{
								if (matNum[i][j] == matNum[i][k])
								{
									matNum[i][j] *= 2;
									matNum[i][k] = 0;
								}
								break;
							}
						}
					}
				}
			}
		}

		if (strCommand == "right")
		{
			for (int i = 0; i < iN; ++i)
			{
				for (int j = iN - 1; j >= 0; --j)
				{
					if (matNum[i][j] == 0)
					{
						for (int k = j - 1; k >= 0; --k)
						{
							if (matNum[i][k] != 0)
							{
								swap(matNum[i][j], matNum[i][k]);
								break;
							}
						}
					}
					if (matNum[i][j] != 0)
					{
						for (int k = j - 1; k >= 0; --k)
						{
							if (matNum[i][k] != 0)
							{
								if (matNum[i][j] == matNum[i][k])
								{
									matNum[i][j] *= 2;
									matNum[i][k] = 0;
								}
								break;
							}
						}
					}
				}
			}
		}
		if (strCommand == "up")
		{
			for (int i = 0; i < iN; ++i)
			{
				for (int j = 0; j < iN; ++j)
				{
					if (matNum[j][i] == 0)
					{
						for (int k = j + 1; k < iN; ++k)
						{
							if (matNum[k][i] != 0)
							{
								swap(matNum[j][i], matNum[k][i]);
								break;
							}
						}
					}
					if (matNum[j][i] != 0)
					{
						for (int k = j + 1; k < iN; ++k)
						{
							if (matNum[k][i] != 0)
							{
								if (matNum[j][i] == matNum[k][i])
								{
									matNum[j][i] *= 2;
									matNum[k][i] = 0;
								}
								break;
							}
						}
					}
				}
			}
		}
		if (strCommand == "down")
		{
			for (int i = 0; i < iN; ++i)
			{
				for (int j = iN - 1; j >= 0; --j)
				{
					if (matNum[j][i] == 0)
					{
						for (int k = j - 1; k >= 0; --k)
						{
							if (matNum[k][i] != 0)
							{
								swap(matNum[j][i], matNum[k][i]);
								break;
							}
						}
					}
					if (matNum[j][i] != 0)
					{
						for (int k = j - 1; k >= 0; --k)
						{
							if (matNum[k][i] != 0)
							{
								if (matNum[j][i] == matNum[k][i])
								{
									matNum[j][i] *= 2;
									matNum[k][i] = 0;
								}
								break;
							}
						}
					}
				}
			}
		}

		cout << "Case #" << t << ":\n";
		for (int i = 0; i < iN; ++i)
		{
			for (int j = 0; j < iN; ++j)
			{
				cout << matNum[i][j] << (j == iN - 1 ? "\n" : " ");
			}
		}
	}
	return 0;
}
