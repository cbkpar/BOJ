import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] dy = {-1, 0, 1, 0};
        int[] dx = {0, -1, 0, 1};
        int n = Integer.parseInt(br.readLine());
        char[][] map = new char[n][n];
        int ty = 0;
        int tx = 0;
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < n; j++) {
                map[i][j] = str.charAt(j);
                if (map[i][j] == '#') {
                    ty = i;
                    tx = j;
                }
            }
        }
        map[ty][tx] = '*';
        boolean[][][] chk = new boolean[n][n][4];
        Queue<pos> q = new LinkedList<>();
        for (int i = 0; i < 4; i++) {
            q.add(new pos(ty, tx, i));
            chk[ty][tx][i] = true;
        }
        int cnt = 0;
        while (!q.isEmpty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                pos p = q.poll();
                int ny = p.y;
                int nx = p.x;
                int dir = p.dir;
                while (true) {
                    ny = ny + dy[dir];
                    nx = nx + dx[dir];
                    if (ny < 0 || ny > n - 1 || nx < 0 || nx > n - 1) break;
                    if (map[ny][nx] == '*') break;
                    if (map[ny][nx] == '.') {
                        if (chk[ny][nx][dir]) break;
                        chk[ny][nx][dir] = true;
                    } else if (map[ny][nx] == '!') {
                        if (!chk[ny][nx][(dir + 1) % 4]) {
                            chk[ny][nx][(dir + 1) % 4] = true;
                            q.add(new pos(ny, nx, (dir + 1) % 4));
                        }
                        if (!chk[ny][nx][(dir + 3) % 4]) {
                            chk[ny][nx][(dir + 1) % 4] = true;
                            q.add(new pos(ny, nx, (dir + 3) % 4));
                        }

                    } else if (map[ny][nx] == '#') {
                        System.out.println(cnt);
                        return;
                    }
                }
            }
            cnt++;
        }
    }
}

class pos {
    int y;
    int x;
    int dir;

    public pos(int y, int x, int dir) {
        this.y = y;
        this.x = x;
        this.dir = dir;
    }
}
