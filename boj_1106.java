import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int c = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int[] dp = new int[c + 101];
        Arrays.fill(dp, 1000000000);
        dp[0] = 0;
        while (n-- > 0) {
            st = new StringTokenizer(br.readLine());
            int cost = Integer.parseInt(st.nextToken());
            int cnt = Integer.parseInt(st.nextToken());
            for (int i = cnt; i <= c + 100; i++) dp[i] = Math.min(dp[i], dp[i - cnt] + cost);
        }
        int mi = Integer.MAX_VALUE;
        for (int i = c; i <= c + 100; i++) mi = Math.min(mi, dp[i]);
        System.out.println(mi);
    }
}
