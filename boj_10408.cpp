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

	vector<int> vecCount(10, 0);

	string strScore;
	cin >> strScore;
	for (char ch : strScore)
	{
		++vecCount[ch - '0'];
	}
	vecCount[1] -= vecCount[0];

	double dAns = 0;
	for (int i = 1; i <= 9; ++i)
	{
		dAns += (double)(i)*vecCount[i];
	}
	dAns += (double)vecCount[0] * 10.0;
	printf("%.02f\n", dAns / (strScore.length() - vecCount[0]));
	return 0;
}
