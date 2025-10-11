#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iW;
	cin >> iN >> iW;

	int iScore = 0;
	iScore += iN * 10;
	if (iN >= 3) iScore += 20;
	if (iN == 5) iScore += 50;
	if (iW > 1000) iScore -= 15;
	if (iScore < 0) iScore = 0;

	cout << iScore << "\n";
	return 0;
}
