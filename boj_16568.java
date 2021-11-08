import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken()) + 1;
        int b = Integer.parseInt(st.nextToken()) + 1;
        int[] dp = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;
            if (i >= a) dp[i] = Math.min(dp[i], dp[i - a] + 1);
            if (i >= b) dp[i] = Math.min(dp[i], dp[i - b] + 1);
        }
        System.out.println(dp[n]);
    }
}
