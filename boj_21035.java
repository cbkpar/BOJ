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
        int[][] map = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int k = Integer.parseInt(br.readLine());
        while (k-- > 0) {
            st = new StringTokenizer(br.readLine());
            String str = st.nextToken();
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken());
            if (str.equals("row")) {
                for (int i = 0; i < m; i++) map[a][i] += b;
            } else {
                for (int i = 0; i < n; i++) map[i][a] += b;
            }
        }
        int mx = Integer.MIN_VALUE;
        int mi = Integer.MAX_VALUE;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += map[i][j];
                mx = Math.max(mx, map[i][j]);
                mi = Math.min(mi, map[i][j]);
            }
        }
        System.out.println(sum + " " + mi + " " + mx);
    }
}
