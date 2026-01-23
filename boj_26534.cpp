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

	vector<int> vecA(6, 0);
	vector<int> vecB(6, 0);

	for (int i = 0;i < 6;++i)
	{
		cin >> vecA[i];
	}
	for (int i = 0;i < 6;++i)
	{
		cin >> vecB[i];
	}

	int iCountA = 0;
	int iCountB = 0;

	for (int i = 0;i < 6;++i)
	{
		for (int j = 0;j < 6;++j)
		{
			if (vecA[i] > vecB[j]) ++iCountA;
			if (vecA[i] < vecB[j]) ++iCountB;
		}
	}

	if (iCountA + iCountB == 0)
	{
		cout << "0.0000" << "\n";
	}
	else
	{
		cout.precision(5);
		cout << fixed;
		cout << ((double)(iCountA) / (double)(iCountA + iCountB)) << "\n";
	}

	return 0;
}
