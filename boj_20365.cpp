#include <iostream>
#include <string>

using namespace std;

int main()
{
	int iN;
	cin >> iN;
	int iCount = 1;
	string strColor;
	cin >> strColor;
	for (int i = 1; i < iN; ++i)
	{
		if (strColor[i] != strColor[i - 1])
		{
			++iCount;
		}
	}
	cout << (iCount / 2 + 1) << endl;
	return 0;
}
