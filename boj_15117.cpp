#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<string> vecLine(iN, "");
	for (int i = 0;i < iN;++i)
	{
		cin >> vecLine[i];
	}

	vector<vector<int>> matNum(iN, vector<int>(iN, 0));
	for (int i = 0;i < iN;++i)
	{
		for (int j = 0;j < iN;++j)
		{
			if (vecLine[i][j] >= 'A' && vecLine[i][j] <= 'Z')
			{
				matNum[i][j] = (vecLine[i][j] - 'A') + 10;
			}
			else
			{
				matNum[i][j] = vecLine[i][j] - '0';
			}
		}
	}
	bool bSquare = true;
	for (int i = 0;i < iN;++i)
	{
		vector<int> vecCount(iN, 0);
		for (int j = 0;j < iN;++j)
		{
			vecCount[matNum[i][j]]++;
		}
		for (int j = 0;j < iN;++j)
		{
			if (vecCount[j] != 1)
			{
				bSquare = false;
			}
		}
	}
	for (int i = 0;i < iN;++i)
	{
		vector<int> vecCount(iN, 0);
		for (int j = 0;j < iN;++j)
		{
			vecCount[matNum[j][i]]++;
		}
		for (int j = 0;j < iN;++j)
		{
			if (vecCount[j] != 1)
			{
				bSquare = false;
			}
		}
	}

	if (bSquare)
	{
		bool bReduce = true;
		for (int i = 1;i < iN;++i)
		{
			if (matNum[0][i] < matNum[0][i - 1])
			{
				bReduce = false;
			}
			if (matNum[i][0] < matNum[i - 1][0])
			{
				bReduce = false;
			}
		}
		if (bReduce)
		{
			cout << "Reduced" << "\n";
		}
		else
		{
			cout << "Not Reduced" << "\n";
		}
	}
	else
	{
		cout << "No" << "\n";
	}


	return 0;
}
