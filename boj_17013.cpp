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

	vector<vector<int>> matNum(2, vector<int>(2, 0));
	matNum[0][0] = 1;
	matNum[0][1] = 2;
	matNum[1][0] = 3;
	matNum[1][1] = 4;

	string strWord;
	cin >> strWord;

	for (char ch : strWord)
	{
		if (ch == 'H')
		{
			swap(matNum[0][0], matNum[1][0]);
			swap(matNum[0][1], matNum[1][1]);
		}
		if (ch == 'V')
		{
			swap(matNum[0][0], matNum[0][1]);
			swap(matNum[1][0], matNum[1][1]);
		}
	}

	cout << matNum[0][0] << " " << matNum[0][1] << "\n";
	cout << matNum[1][0] << " " << matNum[1][1] << "\n";

	return 0;
}
