import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        boolean chk = false;
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int p = Integer.parseInt(st.nextToken());
            if (n == 0 && m == 0 && p == 0) break;
            if (chk) sb.append("\n");
            int[][] ans = new int[n][n];
            int[][] pmat = new int[n][n];
            for (int i = 0; i < n; i++) ans[i][i] = 1;
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) pmat[i][j] = Integer.parseInt(st.nextToken());
            }
            while (p > 0) {
                if (p % 2 == 1) {
                    int[][] tmp = new int[n][n];
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            for (int k = 0; k < n; k++) {
                                tmp[i][j] = (tmp[i][j] + ans[i][k] * pmat[k][j]) % m;
                            }
                        }
                    }
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            ans[i][j] = tmp[i][j];
                        }
                    }
                }
                int[][] tmp = new int[n][n];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        for (int k = 0; k < n; k++) {
                            tmp[i][j] = (tmp[i][j] + pmat[i][k] * pmat[k][j]) % m;
                        }
                    }
                }
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        pmat[i][j] = tmp[i][j];
                    }
                }
                p /= 2;
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n - 1; j++) {
                    sb.append(ans[i][j] + " ");
                }
                sb.append(ans[i][n - 1] + "\n");
            }
            chk = true;
        }
        System.out.println(sb);
    }
}
