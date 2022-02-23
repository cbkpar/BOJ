import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int Ax = Integer.parseInt(st.nextToken());
        int Ay = Integer.parseInt(st.nextToken());
        int Bx = Integer.parseInt(st.nextToken());
        int By = Integer.parseInt(st.nextToken());
        int Cx = Integer.parseInt(st.nextToken());
        int Cy = Integer.parseInt(st.nextToken());
        if ((By - Ay) * (Cx - Ax) == (Cy - Ay) * (Bx - Ax)) {
            System.out.println("-1");
        } else {
            double mx = 0;
            double mi = Double.MAX_VALUE;
            double a = Math.sqrt(Math.pow(Bx - Ax, 2) + Math.pow(By - Ay, 2));
            double b = Math.sqrt(Math.pow(Cx - Bx, 2) + Math.pow(Cy - By, 2));
            double c = Math.sqrt(Math.pow(Ax - Cx, 2) + Math.pow(Ay - Cy, 2));
            mx = Math.max(mx, 2 * a + 2 * b);
            mx = Math.max(mx, 2 * b + 2 * c);
            mx = Math.max(mx, 2 * c + 2 * a);
            mi = Math.min(mi, 2 * a + 2 * b);
            mi = Math.min(mi, 2 * b + 2 * c);
            mi = Math.min(mi, 2 * c + 2 * a);
            System.out.println(mx - mi);
        }
    }
}
