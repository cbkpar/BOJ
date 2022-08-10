#include <iostream>

using namespace std;

int main()
{
	while (true)
	{
		int iA, iB, iC;
		cin >> iA >> iB >> iC;
		if (0 == iA && 0 == iB && 0 == iC)
		{
			break;
		}
		if (iA == 0)
		{
			cout << (iC / iB) << " " << iB << " " << iC << endl;
		}
		else if (iB == 0)
		{
			cout << iA << " " << (iC / iA) << " " << iC << endl;
		}
		else
		{
			cout << iA << " " << iB << " " << (iA*iB) << endl;
		}
	}
	return 0;
}
