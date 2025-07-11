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

	int iSum = 0;
	vector<int> vecVote(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecVote[i];
		iSum += vecVote[i];
	}
	sort(vecVote.begin(), vecVote.end());

	for (int i = 0;i < (iN + 1) / 2;++i)
	{
		iSum -= (vecVote[i] + 1) / 2;
	}

	cout << iSum << "\n";
	return 0;
}
