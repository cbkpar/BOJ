import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] dp = new int[1001];
        StringTokenizer st = new StringTokenizer(br.readLine());
        while (n-- > 0) {
            int t = Integer.parseInt(st.nextToken());
            for (int i = t + 1; i <= 1000; i++) dp[t] = Math.max(dp[t], dp[i] + t);
        }
        int mx = 0;
        for (int i = 1; i <= 1000; i++) mx = Math.max(mx, dp[i]);
        System.out.println(mx);
    }
}
