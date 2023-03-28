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

	int iN, iM;
	cin >> iN >> iM;

	int iMax = 0;
	int iUse = -1;

	vector<long long> vecSong(iN, 0);

	for (int i = 0; i < iN; ++i)
	{
		string strName, strSong;
		cin >> strName >> strSong;

		long long lTemp = 0;
		for (int j = 0; j < iM; ++j)
		{
			lTemp *= 2;
			if (strSong[j] == 'Y') ++lTemp;
		}
		vecSong[i] = lTemp;
	}

	int iWay = 1 << iN;
	for (int i = 0; i < iWay; ++i)
	{
		long long lSong = 0;
		int iUsed = 0;
		for (int j = 0; j < iN; ++j)
		{
			if ((i & (1 << j)) == (1 << j))
			{
				lSong |= vecSong[j];
				++iUsed;
			}
		}
		if (lSong == 0) continue;
		int iSongCount = 0;
		while (lSong)
		{
			if (lSong & 1) ++iSongCount;
			lSong /= 2;
		}
		if (iSongCount > iMax)
		{
			iMax = iSongCount;
			iUse = iUsed;
		}
		else if (iSongCount == iMax)
		{
			iUse = min(iUse, iUsed);
		}
	}
	cout << iUse << "\n";
	return 0;
}
