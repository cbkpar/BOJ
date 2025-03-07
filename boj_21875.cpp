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

	string strA, strB;
	cin >> strA >> strB;

	vector<int> vecNum(2, 0);
	vecNum[0] = abs(strA[0] - strB[0]);
	vecNum[1] = abs(strA[1] - strB[1]);
	sort(vecNum.begin(), vecNum.end());
	cout << vecNum[0] << " " << vecNum[1] << "\n";
	return 0;
}
