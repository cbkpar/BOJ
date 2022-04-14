#include <iostream>
#include <queue>

using namespace std;

class pos
{
public:
    int y, x;
    pos(int _y, int _x)
    {
        y = _y;
        x = _x;
    }
};

int main()
{
    int dy[6] = {-2, -2, 0, 0, 2, 2};
    int dx[6] = {-1, 1, -2, 2, -1, 1};

    int iSize;
    cin >> iSize;
    int iR1, iC1, iR2, iC2;
    cin >> iR1 >> iC1 >> iR2 >> iC2;

    int map[200][200];
    bool chk[200][200];
    queue<pos> q;
    chk[iR1][iC1] = true;
    q.push(pos(iR1, iC1));
    int iCount = 0;
    while (!q.empty())
    {
        int qSize = q.size();
        while (qSize--)
        {
            pos p = q.front();
            q.pop();
            if (p.y == iR2 && p.x == iC2)
            {
                cout << iCount << endl;
                return 0;
            }
            for (int i = 0; i < 6; ++i)
            {
                int ny = p.y + dy[i];
                int nx = p.x + dx[i];
                if (ny < 0 || ny >= iSize || nx < 0 || nx >= iSize)
                {
                    continue;
                }
                if (chk[ny][nx])
                {
                    continue;
                }
                chk[ny][nx] = true;
                q.push(pos(ny, nx));
            }
        }
        ++iCount;
    }
    cout << "-1" << endl;
    return 0;
}
