import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

    static int n;
    static int[][] map;
    static boolean[][] chk;
    static int ans = Integer.MAX_VALUE;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        map = new int[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) map[i][j] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (areachk(i, j, 1, 1)) {
                    chk = new boolean[22][22];
                    dfs(i, j, 1, 1);
                }
            }
        }
        System.out.println(ans);
    }

    private static void dfs(int y, int x, int d1, int d2) {
        int[] arr = new int[5];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i + j >= x + y && i + j <= x + y + d2 * 2 && i - j >= y - x && i - j <= y - x + d1 * 2) {
                    arr[4] += map[i][j];
                } else if (i < y + d1 && j <= x) {
                    arr[0] += map[i][j];
                } else if (i <= y + d2 && j > x) {
                    arr[1] += map[i][j];
                } else if (i >= y + d1 && j < x - d1 + d2) {
                    arr[2] += map[i][j];
                } else if (i > y + d2 && j >= x - d1 + d2) {
                    arr[3] += map[i][j];
                }
            }
        }
        int mx = Integer.MIN_VALUE;
        int mi = Integer.MAX_VALUE;
        for (int i = 0; i < 5; i++) {
            mx = Math.max(mx, arr[i]);
            mi = Math.min(mi, arr[i]);
        }
        ans = Math.min(ans, mx - mi);
        if (areachk(y, x, d1 + 1, d2)) {
            if (!chk[d1 + 1][d2]) {
                chk[d1 + 1][d2] = true;
                dfs(y, x, d1 + 1, d2);
            }
        }
        if (areachk(y, x, d1, d2 + 1)) {
            if (!chk[d1][d2 + 1]) {
                chk[d1][d2 + 1] = true;
                dfs(y, x, d1, d2 + 1);
            }
        }

    }

    private static boolean areachk(int y, int x, int d1, int d2) {
        if (x - d1 < 0 || x + d2 > n - 1 || y + d1 + d2 > n - 1) return false;
        return true;
    }
}
