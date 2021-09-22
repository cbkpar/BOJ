import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, m, i, j, t, ny, nx, cnt;
        int[] dy = {-1, 0, 1, 0};
        int[] dx = {0, -1, 0, 1};
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int[][] map = new int[n][m];
        for (i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        cnt = 0;
        while (true) {
            Queue<pos> q = new LinkedList<>();
            Queue<pos> qc = new LinkedList<>();
            Queue<pos> qd = new LinkedList<>();
            boolean[][] chk = new boolean[n][m];
            q.add(new pos(0, 0));
            chk[0][0] = true;
            while (!q.isEmpty()) {
                pos p = q.poll();
                for (i = 0; i < 4; i++) {
                    ny = p.y + dy[i];
                    nx = p.x + dx[i];
                    if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1) continue;
                    if (chk[ny][nx]) continue;
                    chk[ny][nx] = true;
                    if (map[ny][nx] == 1) {
                        qc.add(new pos(ny, nx));
                    } else {
                        q.add(new pos(ny, nx));
                    }
                }
            }
            if (qc.isEmpty()) {
                System.out.println(cnt);
                return;
            }
            while (!qc.isEmpty()) {
                pos p = qc.poll();
                t = 0;
                for (i = 0; i < 4; i++) {
                    ny = p.y + dy[i];
                    nx = p.x + dx[i];
                    if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1) continue;
                    if (chk[ny][nx] && map[ny][nx] == 0) t++;
                }
                if (t >= 2) qd.add(new pos(p.y, p.x));
            }
            while (!qd.isEmpty()) {
                pos p = qd.poll();
                map[p.y][p.x] = 0;
            }
            cnt++;
        }
    }
}

class pos {
    int y, x;

    public pos(int y, int x) {
        this.y = y;
        this.x = x;
    }
}
