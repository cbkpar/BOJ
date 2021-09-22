import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, m, d, i, j, t, s;
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        s = 0;
        int[][] map = new int[n][m];
        for (i = 0; i < n; i++) {
            String str = br.readLine();
            for (j = 0; j < m; j++) {
                if (str.charAt(j) == '#') map[i][j] = 1;
            }
        }
        for (i = 0; i < n; i++) {
            t = 0;
            for (j = 0; j < m; j++) {
                if (map[i][j] == 0) {
                    if (++t >= d) s++;
                } else {
                    t = 0;
                }
            }
        }
        for (i = 0; i < m; i++) {
            t = 0;
            for (j = 0; j < n; j++) {
                if (map[j][i] == 0) {
                    if (++t >= d) s++;
                } else {
                    t = 0;
                }
            }
        }
        System.out.println(s);
    }
}
