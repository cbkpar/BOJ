/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    
    vector<int> vecNum(20, 0);
    for(int i=0;i<20;++i)
    {
        cin >> vecNum[i];
    }
    
    int iSumA = 0;
    for(int i=0;i<20;++i)
    {
        if(vecNum[i] == 20)
        {
            iSumA += vecNum[i];
            iSumA += vecNum[(i+19)%20];
            iSumA += vecNum[(i+1)%20];
        }
    }

    int iSumB = 0;
    for(int i=0;i<20;++i)
    {
        iSumB += vecNum[i];
    }
    
    if(iSumA * 20 > iSumB * 3)
    {
        cout << "Alice" << "\n";
    }
    else if(iSumA * 20 < iSumB * 3)
    {
        cout << "Bob" << "\n";
    }
    else
    {
        cout << "Tie" << "\n";
    }

    return 0;
}
