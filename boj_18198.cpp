#include <iostream>
#include <string>

using namespace std;

int main()
{
	string strGamePlay;
	cin >> strGamePlay;
	int iScoreA = 0;
	int iScoreB = 0;
	int iLength = strGamePlay.length() / 2;
	for (int i = 0; i < iLength; ++i)
	{
		if (strGamePlay[i * 2] == 'A')
		{
			iScoreA += strGamePlay[i * 2 + 1] - '0';
		}
		else
		{
			iScoreB += strGamePlay[i * 2 + 1] - '0';
		}
	}
	cout << (iScoreA > iScoreB ? "A" : "B") << endl;
	return 0;
}
