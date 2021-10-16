import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        boolean[][] map = new boolean[n + 2][n + 2];
        int[][][] dp = new int[n + 2][n + 2][3];
        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                if (st.nextToken().charAt(0) == '1') {
                    map[i][j] = true;
                }
            }
        }
        dp[1][2][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (!map[i][j + 1]) {
                    dp[i][j + 1][0] += dp[i][j][0] + dp[i][j][1];
                }
                if (!map[i + 1][j]) {
                    dp[i + 1][j][2] += dp[i][j][2] + dp[i][j][1];
                }
                if (!map[i][j + 1] && !map[i + 1][j] && !map[i + 1][j + 1]) {
                    dp[i + 1][j + 1][1] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
                }
            }
        }
        System.out.println(dp[n][n][0] + dp[n][n][1] + dp[n][n][2]);
    }
}
