import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, i, j, k, ans;
        n = Integer.parseInt(br.readLine());
        int[][] A = new int[n][n];
        int[][] B = new int[n][n];
        for (i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (j = 0; j < n; j++) A[i][j] = Integer.parseInt(st.nextToken());
        }
        for (i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (j = 0; j < n; j++) B[i][j] = Integer.parseInt(st.nextToken());
        }
        ans = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                boolean chk = false;
                for (k = 0; k < n; k++) {
                    if (A[i][k] == 1 && B[k][j] == 1) {
                        chk = true;
                        break;
                    }
                }
                if (chk) ans++;
            }
        }
        System.out.println(ans);
    }
}
