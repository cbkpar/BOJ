#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecCocjr(6, 0);
	vector<int> vecEkwoo(6, 0);

	for (int i = 0; i < 6; ++i)
	{
		cin >> vecCocjr[i];
	}
	for (int i = 0; i < 6; ++i)
	{
		cin >> vecEkwoo[i];
	}

	int iScore = 0;
	iScore += vecCocjr[0] * 13;
	iScore += vecCocjr[1] * 7;
	iScore += vecCocjr[2] * 5;
	iScore += vecCocjr[3] * 3;
	iScore += vecCocjr[4] * 3;
	iScore += vecCocjr[5] * 2;

	iScore -= vecEkwoo[0] * 13;
	iScore -= vecEkwoo[1] * 7;
	iScore -= vecEkwoo[2] * 5;
	iScore -= vecEkwoo[3] * 3;
	iScore -= vecEkwoo[4] * 3;
	iScore -= vecEkwoo[5] * 2;
	iScore -= 1;

	if (iScore <= 0)
	{
		cout << "ekwoo" << "\n";
	}
	else
	{
		cout << "cocjr0208" << "\n";
	}
	return 0;
}
