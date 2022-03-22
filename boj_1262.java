import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int r1 = Integer.parseInt(st.nextToken());
        int c1 = Integer.parseInt(st.nextToken());
        int r2 = Integer.parseInt(st.nextToken());
        int c2 = Integer.parseInt(st.nextToken());
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                int tr = i % (2 * n - 1);
                int tc = j % (2 * n - 1);
                tr = Math.abs(tr - (n - 1));
                tc = Math.abs(tc - (n - 1));
                int ts = tr + tc;
                if (ts >= n) {
                    sb.append(".");
                } else {
                    sb.append((char) ('a' + (ts % 26)));
                }

            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
