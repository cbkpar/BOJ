import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        long[] dp = new long[2501];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= 2500; i++) {
            for (int j = i - 1; j >= 0; j--) {
                dp[i] = (dp[i] + dp[j] * dp[i - 1 - j]) % 1000000007;
            }
        }
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            if (n % 2 == 1) {
                sb.append("0\n");
            } else {
                sb.append(dp[n / 2] + "\n");
            }
        }
        System.out.println(sb);
    }
}
