import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, a, b, i, p, q;
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        for (i = n; i < 8; i++) {
            st = new StringTokenizer(br.readLine());
            p = Integer.parseInt(st.nextToken());
            q = Integer.parseInt(st.nextToken());
            if (p >= 6) {
                a += 18;
                b += 18;
            } else if (p + q >= 6) {
                a += p * 3;
                b += 18;
            } else {
                a += p * 3;
                b += (p + q) * 3;
            }
        }
        if (a >= 66 && b >= 130) {
            System.out.println("Nice");
        } else {
            System.out.println("Nae ga wae");
        }
    }
}
