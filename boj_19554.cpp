#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

	int iN;
	cin >> iN;

	int iLeft = 1;
	int iRight = iN;
	while (true)
	{
		int iMid = (iLeft + iRight) / 2;
		cout << "? " << iMid << "\n";

		int iReply;
		cin >> iReply;
		if (iReply == 1)
		{
			iRight = iMid - 1;
		}
		else if (iReply == -1)
		{
			iLeft = iMid + 1;
		}
		else
		{
			cout << "= " << iMid << "\n";
			break;
		}
	}
	return 0;
}
