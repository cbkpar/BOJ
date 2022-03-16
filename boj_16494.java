import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][][] dp = new int[n + 1][m + 1][2];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= 1; k++) {
                    dp[i][j][k] = -10000000;
                }
            }
        }
        dp[0][0][0] = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            int num = Integer.parseInt(st.nextToken());
            for (int j = 0; j <= m; j++) dp[i][j][0] = Math.max(dp[i - 1][j][0], dp[i - 1][j][1]);
            dp[i][0][1] = dp[i - 1][0][1] + num;
            for (int j = 1; j <= m; j++) dp[i][j][1] = Math.max(dp[i - 1][j][1], Math.max(dp[i - 1][j - 1][1], dp[i - 1][j - 1][0])) + num;
        }
        System.out.println(Math.max(dp[n][m][0], dp[n][m][1]));
    }
}
