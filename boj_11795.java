import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        int a, b, c;
        a = b = c = 0;
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            a += Integer.parseInt(st.nextToken());
            b += Integer.parseInt(st.nextToken());
            c += Integer.parseInt(st.nextToken());
            if (a < 30 || b < 30 || c < 30) {
                sb.append("NO\n");
            } else {
                int mi = Math.min(a, Math.min(b, c));
                sb.append(mi + "\n");
                a -= mi;
                b -= mi;
                c -= mi;
            }

        }
        System.out.println(sb);
    }
}
