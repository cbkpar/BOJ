#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int iN, iM;
	cin >> iN >> iM;

	int iSum = 0;
	for (int i = 0;i < iN;++i)
	{
		int iA;
		cin >> iA;
		iSum += iA / iM;
	}
	
	cout << iSum << "\n";
	return 0;
}
