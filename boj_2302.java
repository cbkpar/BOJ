import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] dp = new int[41];
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= 40; i++) dp[i] = dp[i - 1] + dp[i - 2];
        int ans = 1;
        int seat = Integer.parseInt(br.readLine());
        int n = Integer.parseInt(br.readLine());
        int prev = 0;
        while (n-- > 0) {
            int next = Integer.parseInt(br.readLine());
            ans *= dp[next - prev - 1];
            prev = next;
        }
        ans *= dp[seat - prev];
        System.out.println(ans);
    }
}
