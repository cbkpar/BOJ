#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		int iB;
		double dW;
		cin >> iB >> dW;
		double dP = 0;
		for (int j = 0; j < iB; ++j)
		{
			double dR;
			cin >> dR;
			dP += dR * dR * dR;
		}
		dP *= 0.00418879020478639098461685784;
		if (1 != i)
		{
			cout << endl;
		}
		cout << "Data Set " << i << ":" << endl;
		cout << (dP >= dW ? "Yes" : "No") << endl;
	}
	return 0;
}
