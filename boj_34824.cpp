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

	for(int i=0;i<iN;++i)
	{
		string strName;
		cin >> strName;
		if(strName == "yonsei")
		{
			cout << "Yonsei Won!" << "\n";
			break;

		}
		else if(strName == "korea")
		{
			cout << "Yonsei Lost..." << "\n";
			break;
		}
	}

	return 0;
}
