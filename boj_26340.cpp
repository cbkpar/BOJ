#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for(int t=1;t<=iT;++t)
	{
		int iA, iB, iC;
		cin >> iA >> iB >> iC;
		if (t > 1) cout << "\n";
		cout << "Data set: " << iA << " " << iB << " " << iC << "\n";

		while (iC--)
		{
			if (iA > iB)
			{
				iA >>= 1;
			}
			else
			{
				iB >>= 1;
			}
		}
		if (iA < iB) swap(iA, iB);
		cout << iA << " " << iB << "\n";
	}
	return 0;
}
