import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        for (int t = 0; t < 4; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long a = Integer.parseInt(st.nextToken());
            long b = Integer.parseInt(st.nextToken());
            long c = Integer.parseInt(st.nextToken());
            long d = Integer.parseInt(st.nextToken());
            long e = Integer.parseInt(st.nextToken());
            long f = Integer.parseInt(st.nextToken());
            long g = Integer.parseInt(st.nextToken());
            long h = Integer.parseInt(st.nextToken());

            long x1 = Math.min(c, g);
            long x2 = Math.max(a, e);
            long x = 0;
            if (x1 >= x2) x = x1 - x2 + 1;

            long y1 = Math.min(d, h);
            long y2 = Math.max(b, f);
            long y = 0;
            if (y1 >= y2) y = y1 - y2 + 1;

            if (x * y == 0) {
                sb.append("d\n");
            } else if (x * y == 1) {
                sb.append("c\n");
            } else if (x == 1 || y == 1) {
                sb.append("b\n");
            } else {
                sb.append("a\n");
            }
        }
        System.out.println(sb);
    }
}
