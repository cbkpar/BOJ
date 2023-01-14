#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	bool bArr[36] = { false, };
	while (iN--)
	{
		int iNumber;
		cin >> iNumber;
		bArr[iNumber] = true;
	}

	int iScore = 0;

	for (int i = 3; i <= 35; ++i)
	{
		if (!bArr[i - 1] && bArr[i])
		{
			iScore += i;
		}
	}

	cout << iScore << "\n";

	return 0;
}
