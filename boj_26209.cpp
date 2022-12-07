#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool bIsCorrect = true;
	for (int i = 0; i < 8; ++i)
	{
		int iNumber;
		cin >> iNumber;
		if (iNumber == 9)
		{
			bIsCorrect = false;
		}
	}
	cout << (bIsCorrect ? "S\n" : "F\n");
	return 0;
}
