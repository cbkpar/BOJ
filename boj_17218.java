import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String A = br.readLine();
        String B = br.readLine();
        int n = A.length();
        int m = B.length();
        int[][] dp = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (A.charAt(i - 1) == B.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int t = dp[n][m];
        int y = n;
        int x = m;
        Stack<Character> stack = new Stack<>();
        while (t > 0) {
            while (true) {
                if (dp[y][x - 1] != t) break;
                x--;
            }
            while (true) {
                if (dp[y - 1][x] != t) break;
                y--;
            }
            stack.add(A.charAt(y - 1));
            x--;
            y--;
            t--;
        }
        while (!stack.isEmpty()) sb.append(stack.pop());
        System.out.println(sb);
    }
}
