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

    vector<vector<string>> vecWord(iN, vector<string>());
    for (int i = 0; i < iN; ++i)
    {
        int iM;
        cin >> iM;
        for (int j = 0; j < iM; ++j)
        {
            string strWord;
            cin >> strWord;
            vecWord[i].push_back(strWord);
        }
    }
    int iSize = vecWord[0].size();
    cout << iSize << "\n";
    for (int i = 0; i < iSize; ++i)
    {
        cout << vecWord[0][i] << "\n";
    }

	return 0;
}
