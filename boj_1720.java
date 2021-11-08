import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] dp = new int[31];
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= 30; i++) dp[i] = dp[i - 1] + dp[i - 2] * 2;
        int n = Integer.parseInt(br.readLine());
        if (n % 2 == 0) {
            System.out.println((dp[n] + dp[n / 2] + dp[n / 2 - 1] * 2) / 2);
        } else {
            System.out.println((dp[n] + dp[(n - 1) / 2]) / 2);
        }
    }
}
