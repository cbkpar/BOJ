#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> vecNum(2, 0);
    cin >> vecNum[0] >> vecNum[1];

    int iAns = 2;
    while(true)
    {
        int iNum;
        cin >> iNum;
        int iSize = vecNum.size();

        vecNum.push_back((vecNum[iSize-1]+vecNum[iSize-2])%10);
        ++iAns;

        if(vecNum[0]==vecNum[iSize-1]&&vecNum[1]==vecNum[iSize]) break;
    }

    cout << iAns << "\n";
    return 0;
}
