import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] A = new int[n];
        String str = br.readLine();
        for (int i = 0; i < n; i++) A[i] = str.charAt(i) - '0';
        int[] B = new int[n];
        str = br.readLine();
        for (int i = 0; i < n; i++) B[i] = str.charAt(i) - '0';
        int[][] cost = new int[n][10];
        for (int i = 0; i < 10; i++) cost[0][i] = 10000000;
        int diff = (B[0] - A[0] + 10) % 10;
        cost[0][0] = (10 - diff) % 10;
        cost[0][diff] = diff;
        for (int i = 1; i < n; i++) {
            diff = (B[i] - A[i] + 10) % 10;
            for (int j = 0; j < 10; j++) cost[i][j] = cost[i - 1][j] + (10 + j - diff) % 10;
            for (int j = 0; j < 10; j++) cost[i][diff] = Math.min(cost[i][diff], cost[i - 1][j] + (diff - j + 10) % 10);
        }
        int mi = Integer.MAX_VALUE;
        for (int i = 0; i < 10; i++) {
            mi = Math.min(mi, cost[n - 1][i]);
        }
        System.out.println(mi);
    }
}
