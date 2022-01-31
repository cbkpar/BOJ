import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n;
    static int m;
    static int mx;
    static boolean[][] map;
    static boolean[][] chk;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, -1, 0, 1};

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new boolean[n][m];
        chk = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) if (str.charAt(j) == '#') map[i][j] = true;
        }
        btr(0, 1);
        System.out.println(mx);
    }

    private static void btr(int t, int s) {
        if (t == 2) {
            mx = Math.max(mx, s);
            return;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (chk[i][j]) continue;
                if (!chk[i][j] && map[i][j]) {
                    chk[i][j] = true;
                    btr(t + 1, s);
                    int sz = 1;
                    while (true) {
                        int tmp = 0;
                        for (int k = 0; k < 4; k++) {
                            int ny = i + dy[k] * sz;
                            int nx = j + dx[k] * sz;
                            if (ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1) continue;
                            if (chk[ny][nx] || !map[ny][nx]) continue;
                            tmp++;
                        }
                        if (tmp != 4) {
                            while (sz > 1) {
                                sz--;
                                for (int k = 0; k < 4; k++) {
                                    int ny = i + dy[k] * sz;
                                    int nx = j + dx[k] * sz;
                                    chk[ny][nx] = false;
                                }
                            }
                            break;
                        }

                        for (int k = 0; k < 4; k++) {
                            int ny = i + dy[k] * sz;
                            int nx = j + dx[k] * sz;
                            chk[ny][nx] = true;
                        }
                        btr(t + 1, s * (sz * 4 + 1));
                        sz++;
                    }
                    chk[i][j] = false;
                }

            }
        }

    }
}
