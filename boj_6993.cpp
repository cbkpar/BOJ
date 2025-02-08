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

	for (int i = 0;i < iN;++i)
	{
		string strWord;
		cin >> strWord;
		int iShift;
		cin >> iShift;
		int iLen = strWord.length();

		cout << "Shifting " << strWord << " by " << iShift << " positions gives us: ";
		for (int j = 0;j < iLen;++j)
		{
			cout << strWord[(iLen - iShift + j) % iLen];
		}
		cout << "\n";
	}

	return 0;
}
