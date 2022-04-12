import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, m, k;
    static boolean[][] map;
    static int ans = 0;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, -1, 0, 1};

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        map = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                if (str.charAt(j) == 'T') map[i][j] = true;
            }
        }
        map[n - 1][0] = true;
        dfs(n - 1, 0, 1);
        System.out.println(ans);
    }

    static void dfs(int y, int x, int t) {
        if (y == 0 && x == m - 1) {
            if (k == t) ans++;
            return;
        }
        if (t >= k) return;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1) continue;
            if (map[ny][nx]) continue;
            map[ny][nx] = true;
            dfs(ny, nx, t + 1);
            map[ny][nx] = false;
        }
    }
}
