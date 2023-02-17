#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;

	for (int t = 1; t <= iT; ++t)
	{
		int iN;
		cin >> iN;
		vector<int> arrA(iN);
		vector<int> arrB(iN);
		for (int i = 0; i < iN; ++i) cin >> arrA[i];
		for (int i = 0; i < iN; ++i) cin >> arrB[i];

		sort(arrA.begin(), arrA.end());
		sort(arrB.begin(), arrB.end(), greater<>());

		int iSum = 0;
		for (int i = 0; i < iN; ++i) iSum += arrA[i] * arrB[i];

		cout << "Case #" << t << ": " << iSum << "\n";
	}

	return 0;
}
