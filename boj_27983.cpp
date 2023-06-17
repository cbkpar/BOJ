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

	int iN;
	cin >> iN;

	vector<int> vecX(iN, 0);
	vector<int> vecL(iN, 0);
	vector<string> vecColor(iN, "");
	for (int i = 0; i < iN; ++i) cin >> vecX[i];
	for (int i = 0; i < iN; ++i) cin >> vecL[i];
	for (int i = 0; i < iN; ++i) cin >> vecColor[i];
	for (int i = 0; i < iN; ++i)
	{
		for (int j = i + 1; j < iN; ++j)
		{
			if (abs(vecX[i] - vecX[j]) <= vecL[i] + vecL[j] && vecColor[i] != vecColor[j])
			{
				cout << "YES\n";
				cout << (i + 1) << " " << (j + 1) << "\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}
