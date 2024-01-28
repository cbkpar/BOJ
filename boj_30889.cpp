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

	vector<vector<bool>> matVisited(10, vector<bool>(21, false));

	int iN;
	cin >> iN;
	while (iN--)
	{
		string strSeat;
		cin >> strSeat;
		int iLen = strSeat.length();
		int iNum = 0;
		for (int i = 1;i < iLen;++i)
		{
			iNum *= 10;
			iNum += strSeat[i] - '0';
		}
		matVisited[strSeat[0] - 'A'][iNum] = true;
	}

	for (int i = 0;i < 10;++i)
	{
		for (int j = 1;j <= 20;++j)
		{
			cout << (matVisited[i][j] ? "o" : ".");
		}
		cout << "\n";
	}
	return 0;
}
