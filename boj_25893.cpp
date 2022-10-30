#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iFirst, iSecond, iThird;
		cin >> iFirst >> iSecond >> iThird;
		int iCount = 0;
		if (iFirst >= 10)
		{
			++iCount;
		}
		if (iSecond >= 10)
		{
			++iCount;
		}
		if (iThird >= 10)
		{
			++iCount;
		}
		
		cout << iFirst << " " << iSecond << " " << iThird << "\n";
		switch (iCount)
		{
		case 3:
			cout << "triple-double\n";
			break;
		case 2:
			cout << "double-double\n";
			break;
		case 1:
			cout << "double\n";
			break;
		case 0:
			cout << "zilch\n";
			break;
		}
		if (iT != 0)
		{
			cout << "\n";
		}
	}
	return 0;
}
