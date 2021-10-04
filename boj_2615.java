import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int i, j;
        int[][] map = new int[21][21];
        for (i = 1; i < 20; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (j = 1; j < 20; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int[][][] dp = new int[21][21][4];
        for (i = 1; i < 20; i++) {
            for (j = 1; j < 20; j++) {
                if (map[i][j] != 0) {
                    dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = dp[i][j][3] = 1;
                }
                if (map[i - 1][j - 1] == map[i][j]) {
                    dp[i][j][0] += dp[i - 1][j - 1][0];
                }
                if (map[i - 1][j] == map[i][j]) {
                    dp[i][j][1] += dp[i - 1][j][1];
                }
                if (map[i][j - 1] == map[i][j]) {
                    dp[i][j][2] += dp[i][j - 1][2];
                }
                if (map[i - 1][j + 1] == map[i][j]) {
                    dp[i][j][3] += dp[i - 1][j + 1][3];
                }
            }
        }
        for (i = 19; i >= 1; i--) {
            for (j = 19; j >= 1; j--) {
                if (dp[i][j][0] == 6) dp[i - 1][j - 1][0] = 0;
                if (dp[i][j][1] == 6) dp[i - 1][j][1] = 0;
                if (dp[i][j][2] == 6) dp[i][j - 1][2] = 0;
                if (dp[i][j][3] == 6) dp[i - 1][j + 1][3] = 0;
                if (dp[i][j][0] == 5) {
                    System.out.println(map[i][j] + "\n" + (i - 4) + " " + (j - 4));
                    return;
                }
                if (dp[i][j][1] == 5) {
                    System.out.println(map[i][j] + "\n" + (i - 4) + " " + j);
                    return;
                }
                if (dp[i][j][2] == 5) {
                    System.out.println(map[i][j] + "\n" + i + " " + (j - 4));
                    return;
                }
                if (dp[i][j][3] == 5) {
                    System.out.println(map[i][j] + "\n" + i + " " + j);
                    return;
                }
            }
        }
        System.out.println("0");
    }
}
