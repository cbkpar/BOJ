import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        long[] dp = new long[10001];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= 10000; i++) dp[i] = dp[i - 3] + i / 2 + 1;
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            sb.append(dp[Integer.parseInt(br.readLine())] + "\n");
        }
        System.out.println(sb);
    }
}
