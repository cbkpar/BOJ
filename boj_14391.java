import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        String[] arr = new String[n];
        for (int i = 0; i < n; i++) arr[i] = br.readLine();
        int mx = 1 << n * m;
        boolean[][] map = new boolean[n][m];
        int ans = 0;
        for (int k = 0; k < mx; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if ((k & 1 << (i * m + j)) != 0) {
                        map[i][j] = true;
                    } else {
                        map[i][j] = false;
                    }
                }
            }
            int sum = 0;
            for (int i = 0; i < m; i++) {
                int tmp = 0;
                for (int j = 0; j < n; j++) {
                    if (!map[j][i]) {
                        tmp = tmp * 10 + arr[j].charAt(i) - '0';
                    } else {
                        sum += tmp;
                        tmp = 0;
                    }
                }
                sum += tmp;
            }
            for (int i = 0; i < n; i++) {
                int tmp = 0;
                for (int j = 0; j < m; j++) {
                    if (map[i][j]) {
                        tmp = tmp * 10 + arr[i].charAt(j) - '0';
                    } else {
                        sum += tmp;
                        tmp = 0;
                    }
                }
                sum += tmp;
            }
            ans = Math.max(ans, sum);
        }
        System.out.println(ans);
    }
}
