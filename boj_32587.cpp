#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN;
	cin >> iN;

	string strA, strB;
	cin >> strA >> strB;

	int iScore = 0;
	for (int i = 0;i < iN;++i)
	{
		if (strA[i] == 'P' && strB[i] == 'S') --iScore;
		if (strA[i] == 'P' && strB[i] == 'R') ++iScore;
		if (strA[i] == 'S' && strB[i] == 'R') --iScore;
		if (strA[i] == 'S' && strB[i] == 'P') ++iScore;
		if (strA[i] == 'R' && strB[i] == 'P') --iScore;
		if (strA[i] == 'R' && strB[i] == 'S') ++iScore;
	}

	if (iScore < 0)
	{
		cout << "defeat" << "\n";
	}
	else
	{
		cout << "victory" << "\n";
	}
	return 0;
}
