import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, i, k;
        n = Integer.parseInt(br.readLine());
        int[][] arr = new int[n][2];
        for (i = 1; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }
        k = Integer.parseInt(br.readLine());
        int[][] dp = new int[n + 1][2];
        if (n == 1) {
            System.out.println("0");
            return;
        }
        if (n == 2) {
            System.out.println(arr[1][0]);
            return;
        }
        if (n >= 3) {
            dp[2][0] = arr[1][0];
            dp[3][0] = Math.min(arr[1][0] + arr[2][0], arr[1][1]);
            if (n == 3) {
                System.out.println(dp[3][0]);
                return;
            }
            dp[1][1] = dp[2][1] = dp[3][1] = 999999;
            for (i = 4; i <= n; i++) {
                dp[i][0] = Math.min(dp[i - 1][0] + arr[i - 1][0], dp[i - 2][0] + arr[i - 2][1]);
                dp[i][1] = Math.min(Math.min(dp[i - 1][1] + arr[i - 1][0], dp[i - 2][1] + arr[i - 2][1]), dp[i - 3][0] + k);
            }
            System.out.println(Math.min(dp[n][0], dp[n][1]));
        }
    }
}
