#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	for(int t=0;t<iN;++t)
	{
		long long lX;
		cin >> lX;

		bool bFound = false;

		long long lSqrt = (long long)sqrtf(lX);
		for(long long i = lSqrt; i>= 1; --i)
		{
			if(2*i*i < lX) break;
			if(lX%i ==0)
			{
				bFound = true;
				break;
			}
		}

		if(bFound)
		{
			cout << "1" << "\n";
		}
		else
		{
			cout << "0" << "\n";
		}
	}

	return 0;
}
