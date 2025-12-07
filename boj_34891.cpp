#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int iN, iM;
    cin >> iN >> iM;

    int iAns = (iN+iM-1)/iM;
    
    cout << iAns << "\n";
    return 0;
}
