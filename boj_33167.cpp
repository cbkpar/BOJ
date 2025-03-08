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
	string strA, strB;
	cin >> strA >> strB;

	int iA = 0;
	int iB = 0;

	for (int i = 0; i < iN; ++i)
	{
		if (strA[i] == 'R' && strB[i] == 'S') ++iA;
		if (strA[i] == 'R' && strB[i] == 'P') ++iB;
		if (strA[i] == 'S' && strB[i] == 'P') ++iA;
		if (strA[i] == 'S' && strB[i] == 'R') ++iB;
		if (strA[i] == 'P' && strB[i] == 'R') ++iA;
		if (strA[i] == 'P' && strB[i] == 'S') ++iB;
	}
	cout << iA << " " << iB << "\n";
	return 0;
}
