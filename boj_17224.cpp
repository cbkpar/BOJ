#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iL, iK;
	cin >> iN >> iL >> iK;

	int iHard = 0;
	int iEasy = 0;

	while (iN--)
	{
		int iSub1, iSub2;
		cin >> iSub1 >> iSub2;
		if (iL >= iSub2)
		{
			++iHard;
		}
		else if (iL >= iSub1)
		{
			++iEasy;
		}
	}
	
	int iScore = 0;
	while (iK--)
	{
		if (iHard > 0)
		{
			--iHard;
			iScore += 140;
		}
		else if (iEasy > 0)
		{
			--iEasy;
			iScore += 100;
		}
	}

	cout << iScore << "\n";

	return 0;
}
