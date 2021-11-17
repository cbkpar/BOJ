import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] dy = {-1, 0, 1, 0};
        int[] dx = {0, -1, 0, 1};
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] map = new int[n][m];
        boolean[][][] chk = new boolean[n][m][128];
        Queue<pos> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                if (str.charAt(j) == '#') {
                    map[i][j] = -1;
                } else if (str.charAt(j) == '0') {
                    q.add(new pos(i, j, 1));
                } else if (str.charAt(j) == '1') {
                    map[i][j] = -2;
                } else if (str.charAt(j) >= 'a' && str.charAt(j) <= 'f') {
                    map[i][j] = str.charAt(j) - 'a' + 1;
                } else if (str.charAt(j) >= 'A' && str.charAt(j) <= 'F') {
                    map[i][j] = str.charAt(j) - 'A' + 11;
                }
            }
        }
        int cnt = 0;
        while (!q.isEmpty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                pos p = q.poll();
                if (map[p.y][p.x] == -2) {
                    System.out.println(cnt);
                    return;
                }
                for (int j = 0; j < 4; j++) {
                    int ny = p.y + dy[j];
                    int nx = p.x + dx[j];
                    if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1) continue;
                    if (chk[ny][nx][p.key]) continue;
                    chk[ny][nx][p.key] = true;
                    if (map[ny][nx] == -1) continue;
                    if (map[ny][nx] == 0 || map[ny][nx] == -2) {
                        q.add(new pos(ny, nx, p.key));
                    } else if (map[ny][nx] >= 1 && map[ny][nx] <= 10) {
                        q.add(new pos(ny, nx, p.key | (1 << map[ny][nx])));
                    } else if (map[ny][nx] >= 11 && map[ny][nx] <= 20) {
                        if ((p.key & (1 << (map[ny][nx] - 10))) == (1 << (map[ny][nx] - 10))) {
                            q.add(new pos(ny, nx, p.key));
                        }
                    }
                }
            }
            cnt++;
        }
        System.out.println("-1");
    }
}

class pos {
    int y;
    int x;
    int key;

    public pos(int y, int x, int key) {
        this.y = y;
        this.x = x;
        this.key = key;
    }
}
