#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<int> vecScore(8, 0);
	for (int i = 0; i < 8; ++i) cin >> vecScore[i];

	if (iN * iM == 2)
	{
		cout << "ChongChong" << "\n";
	}
	else
	{
		cout << "GomGom" << "\n";
	}
	return 0;
}
