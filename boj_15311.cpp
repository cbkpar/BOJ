#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecNum(2001, 0);

	for(int i=1;i<1001;++i)
	{
		vecNum[i] = 1;
		vecNum[i+1000] = 1000;
	}
    
    cout << "2000\n";
	for(int i=1;i<=2000;++i)
	{
		cout << vecNum[i] << (i==2000?"\n":" ");
	}
	return 0;
}
