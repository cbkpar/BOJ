#include <iostream>

using namespace std;

int main()
{
    int condo[10000][2];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> condo[i][0] >> condo[i][1];
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        bool chk = true;
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
            {
                continue;
            }
            if (condo[j][0] <= condo[i][0] && condo[j][1] <= condo[i][1])
            {
                chk = false;
                break;
            }
        }
        if (chk)
        {
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}
