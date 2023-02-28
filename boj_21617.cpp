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

	vector<int> vecA(iN + 1);
	vector<int> vecB(iN);
	for (int i = 0; i <= iN; ++i) cin >> vecA[i];
	for (int i = 0; i < iN; ++i) cin >> vecB[i];

	int iSum = 0;
	for (int i = 0; i < iN; ++i) iSum += (vecA[i] + vecA[i + 1]) * vecB[i];

	cout << (iSum / 2) << "." << (iSum % 2 == 0 ? "0" : "5") << "\n";

	return 0;
}
