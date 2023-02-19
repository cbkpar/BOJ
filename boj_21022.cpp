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

	int iScore = 0;

	vector<int> vecScoreA(iN);
	vector<int> vecScoreB(iN);
	for (int i = 0; i < iN; ++i) cin >> vecScoreA[i];
	for (int i = 0; i < iN; ++i) cin >> vecScoreB[i];
	for (int i = 0; i < iN; ++i)
	{
		if (vecScoreA[i] > vecScoreB[i])
		{
			iScore += 3;
		}
		else if (vecScoreA[i] == vecScoreB[i])
		{
			iScore += 1;
		}
	}

	cout << iScore << "\n";

	return 0;
}
