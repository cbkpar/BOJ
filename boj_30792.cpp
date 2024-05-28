#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iRank = 1;
	int iVote;
	cin >> iVote;

	for (int i = 1;i < iN;++i)
	{
		int iNum;
		cin >> iNum;
		if (iNum > iVote) ++iRank;
	}

	cout << iRank << "\n";
	return 0;
}
