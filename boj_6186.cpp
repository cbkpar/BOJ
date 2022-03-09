#include <string.h>

#include <iostream>

using namespace std;

int main() {
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};
    int r, c;
    string str;
    cin >> r >> c;
    int map[r][c] = {0};
    for (int i = 0; i < r; i++) {
        cin >> str;
        for (int j = 0; j < c; j++) {
            if (str[j] == '#') map[i][j] = 1;
        }
    }
    int cnt = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] == 1) {
                cnt++;
                map[i][j] = 0;
                for (int k = 0; k < 4; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (nr < 0 || nr > r - 1 || nc < 0 || nc > c - 1) continue;
                    map[nr][nc] = 0;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
