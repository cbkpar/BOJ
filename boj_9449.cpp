#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iW, iH, iw, ih;
	cin >> iW >> iH >> iw >> ih;

	int iNowW = (iW / iw + 1) / 2;
	int iNowH = (iH / ih + 1) / 2;

	cout << (iNowW * iNowH) << "\n";
	return 0;
}
