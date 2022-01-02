import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, m, k;
    static int[][] map;
    static boolean[][] chk;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, -1, 0, 1};
    static int mx = Integer.MIN_VALUE;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        map = new int[n][m];
        chk = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) map[i][j] = Integer.parseInt(st.nextToken());
        }
        btr(0, 0, 0);
        System.out.println(mx);

    }

    private static void btr(int t, int cnt, int sum) {
        if (cnt == k) {
            mx = Math.max(mx, sum);
            return;
        }
        for (int i = t; i < n * m; i++) {
            int y = i / m;
            int x = i % m;
            boolean ispossible = true;
            for (int j = 0; j < 4; j++) {
                int ny = y + dy[j];
                int nx = x + dx[j];
                if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1) continue;
                if (chk[ny][nx]) ispossible = false;
            }
            if (ispossible) {
                chk[y][x] = true;
                btr(i + 1, cnt + 1, sum + map[y][x]);
                chk[y][x] = false;
            }
        }
    }
}
