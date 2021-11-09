import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        BigInteger[] dp = new BigInteger[10001];
        dp[1] = new BigInteger("1");
        dp[2] = new BigInteger("1");
        for (int i = 3; i <= 10000; i++) dp[i] = dp[i - 1].add(dp[i - 2]);
        int t = Integer.parseInt(br.readLine());
        for (int i = 1; i <= t; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            BigInteger q = new BigInteger(st.nextToken());
            sb.append("Case #" + i + ": " + dp[n].remainder(q) + "\n");
        }
        System.out.println(sb);
    }
}
