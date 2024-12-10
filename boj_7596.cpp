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

	int iT = 0;
	while(true)
	{
		int iN;
		cin >> iN;
		if(iN == 0) break;

		cin.ignore();
		vector<string> vecWord(iN, "");
		for(int i=0;i<iN;++i)
		{
			getline(cin, vecWord[i]);
		}
		sort(vecWord.begin(), vecWord.end());

		cout << ++iT << "\n";
		for(int i=0;i<iN;++i)
		{
			cout << vecWord[i] << "\n";
		}
	}

	return 0;
}
