#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	bool bKey = false;
	bool bPhone = false;
	bool bWallet = false;

	for(int i=0;i<iN;++i)
	{
		string strWord;
		cin >> strWord;
		if(strWord == "keys") bKey = true;
		if(strWord == "phone") bPhone = true;
		if(strWord == "wallet") bWallet = true;
	}

	if(bKey && bPhone && bWallet)
	{
		cout << "ready" << "\n";
	}
	else
	{
		if(!bKey) cout << "keys" << "\n";
		if(!bPhone) cout << "phone" << "\n";
		if(!bWallet) cout << "wallet" << "\n";
	}

	return 0;
}
