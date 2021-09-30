import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, m, i, j, y, x, d, cnt, sz, ty, tx;
        int[] dy = {0, 0, 0, 1, -1};
        int[] dx = {0, 1, -1, 0, 0};
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int[][] map = new int[n + 1][m + 1];
        for (i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (j = 1; j <= m; j++) map[i][j] = Integer.parseInt(st.nextToken());
        }
        boolean[][][] chk = new boolean[n + 1][m + 1][5];
        Queue<loc> q = new LinkedList<>();
        st = new StringTokenizer(br.readLine());
        y = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        q.add(new loc(y, x, d));
        st = new StringTokenizer(br.readLine());
        y = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        cnt = 0;
        while (!q.isEmpty()) {
            sz = q.size();
            for (i = 0; i < sz; i++) {
                loc p = q.poll();
                if (y == p.y && x == p.x && d == p.d) {
                    System.out.println(cnt);
                    return;
                }
                for (j = 1; j <= 3; j++) {
                    ty = p.y + dy[p.d] * j;
                    tx = p.x + dx[p.d] * j;
                    if (ty <= 0 || ty > n || tx <= 0 || tx > m) continue;
                    if (chk[ty][tx][p.d]) continue;
                    if (map[ty][tx] == 1) break;
                    chk[ty][tx][p.d] = true;
                    q.add(new loc(ty, tx, p.d));
                }
                if (p.d <= 2) {
                    if (!chk[p.y][p.x][3]) {
                        chk[p.y][p.x][3] = true;
                        q.add(new loc(p.y, p.x, 3));
                    }
                    if (!chk[p.y][p.x][4]) {
                        chk[p.y][p.x][4] = true;
                        q.add(new loc(p.y, p.x, 4));
                    }
                } else {
                    if (!chk[p.y][p.x][1]) {
                        chk[p.y][p.x][1] = true;
                        q.add(new loc(p.y, p.x, 1));
                    }
                    if (!chk[p.y][p.x][2]) {
                        chk[p.y][p.x][2] = true;
                        q.add(new loc(p.y, p.x, 2));
                    }
                }
            }
            cnt++;
        }

    }
}

class loc {
    int y, x, d;

    public loc(int y, int x, int d) {
        this.y = y;
        this.x = x;
        this.d = d;
    }
}
