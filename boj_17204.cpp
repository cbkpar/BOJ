#include <iostream>

using namespace std;

int arrTarget[151] = { 0, };
bool arrVisited[151] = { false, };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;
	for (int i = 0; i < iN; ++i)
	{
		cin >> arrTarget[i];
	}
	int iCount = 0;
	int iNow = 0;
	arrVisited[0] = true;
	while (true)
	{
		++iCount;
		if (arrTarget[iNow] == iK)
		{
			cout << iCount << "\n";
			return 0;
		}
		if (arrVisited[arrTarget[iNow]])
		{
			break;
		}
		iNow = arrTarget[iNow];
		arrVisited[iNow] = true;
	}
	cout << "-1\n";
	return 0;
}
