#include <iostream>

using namespace std;

int main()
{
	int iSum = 0;
	while (true)
	{
		int iInput;
		cin >> iInput;
		if (-1 == iInput)
		{
			break;
		}
		iSum += iInput;
	}
	cout << iSum << endl;
	return 0;
}
