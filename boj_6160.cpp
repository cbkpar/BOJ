#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	vector<tuple<int, int, int>> vecVote(iN, make_tuple(0, 0, 0));
	for (int i = 0;i < iN;++i)
	{
		cin >> get<0>(vecVote[i]) >> get<1>(vecVote[i]);
		get<2>(vecVote[i]) = i + 1;
	}
	sort(vecVote.begin(), vecVote.end(), greater<>());

	int iAns = -1;
	int iMaxCount = -1;

	for (int i = 0;i < iK;++i)
	{
		if (iMaxCount < get<1>(vecVote[i]))
		{
			iAns = get<2>(vecVote[i]);
			iMaxCount = get<1>(vecVote[i]);
		}
	}

	cout << iAns << "\n";
	return 0;
}
