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
		int iN;
		cin >> iN;
		long long lW, lC;
		lW = 1;
		lC = 100000;
		while (iN--)
		{
			long long lTempW, lTempC;
			cin >> lTempW >> lTempC;
			if (lW * lTempC == lTempW * lC)
			{
				if (lTempC < lC)
				{
					lW = lTempW;
					lC = lTempC;
				}
			}
			else if (lW * lTempC < lTempW * lC)
			{
				lW = lTempW;
				lC = lTempC;
			}
		}
		cout << lC << "\n";
	}
	return 0;
}
