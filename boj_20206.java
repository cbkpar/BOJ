import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long a, b, c, x1, x2, y1, y2, t1, t2, d1, d2;
        StringTokenizer st = new StringTokenizer(br.readLine());
        a = Long.parseLong(st.nextToken());
        b = Long.parseLong(st.nextToken());
        c = Long.parseLong(st.nextToken());
        st = new StringTokenizer(br.readLine());
        x1 = Long.parseLong(st.nextToken());
        x2 = Long.parseLong(st.nextToken());
        y1 = Long.parseLong(st.nextToken());
        y2 = Long.parseLong(st.nextToken());
        t1 = -c - a * x1;
        t2 = -c - a * x2;
        d1 = y1 * b;
        d2 = y2 * b;
        if (Math.min(t1, t2) >= Math.max(d1, d2) || Math.max(t1, t2) <= Math.min(d1, d2)) {
            System.out.println("Lucky");
        } else {
            System.out.println("Poor");
        }
    }
}
