import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String a = br.readLine();
        String b = br.readLine();
        int asz = a.length();
        int bsz = b.length();
        int mx = 0;
        int[][] dp = new int[asz + 1][bsz + 1];
        for (int i = 1; i <= asz; i++) {
            for (int j = 1; j <= bsz; j++) {
                if (a.charAt(i - 1) == b.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    mx = Math.max(mx, dp[i][j]);
                }
            }
        }
        System.out.println(mx);
    }
}
