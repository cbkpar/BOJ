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

    vector<int> vecNum(iN, 0);
    for (int i = 0;i < iN;++i)
    {
        cin >> vecNum[i];
    }

    sort(vecNum.begin(), vecNum.end());
    int iBefore = 0;
    int iCount = 0;
    for (int i = 0;i < iN;++i)
    {
        if (vecNum[i] >= iBefore * 2)
        {
            ++iCount;
            iBefore = vecNum[i];
        }
    }

    cout << iCount << "\n";
	return 0;
}
