import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int[][] dp = new int[46][2];
        dp[1][0] = dp[1][1] = 1;
        for (int i = 2; i <= 45; i++) {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i - 1][0];
        }
        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            int n = Integer.parseInt(br.readLine());
            sb.append("Scenario #" + t + ":\n" + (dp[n][0] + dp[n][1]) + "\n");
            if (t != T) sb.append("\n");
        }
        System.out.println(sb);
    }
}
