import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] cost = new int[n];
        int[] happy = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) cost[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) happy[i] = Integer.parseInt(st.nextToken());
        int[] dp = new int[101];
        for (int i = 0; i < n; i++) {
            int t = cost[i];
            for (int j = 100; j >= t; j--) {
                dp[j] = Math.max(dp[j], dp[j - t] + happy[i]);
            }
        }
        int mx = 0;
        for (int i = 0; i < 100; i++) mx = Math.max(mx, dp[i]);
        System.out.println(mx);
    }
}
