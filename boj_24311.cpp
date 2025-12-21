#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t1, t2, t3, t4, t5, t6, t7;
	cin >> t1 >> t2 >> t3 >> t4 >> t5 >> t6 >> t7;

	int iTime = t1 * 60 + t2;
	iTime -= 10;
	iTime -= t3;
	iTime -= t4 * 60 + t5;
	iTime -= (t6 + 1) * t7;
	printf("%02d %02d",iTime/60,iTime%60);

	return 0;
}
