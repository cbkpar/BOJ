#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int iN;
	cin >> iN;
	
	vector<long long> vecNum(iN+2, 0);
	for(int i=1;i<=iN;++i) cin >> vecNum[i];
	
	vector<long long> vecRight(iN+2, 0);
	
	for(int i=iN;i>=1;--i) vecRight[i] = min(vecRight[i+1]+1, vecNum[i]);
	
	long long lAns = 0;
	for(int i=1;i<=iN;++i) lAns += vecRight[i];
	
	cout << lAns << "\n";
	return 0;
}
