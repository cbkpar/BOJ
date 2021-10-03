import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t, n, k, d, i;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            n = Integer.parseInt(br.readLine());
            d = 1;
            k = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (i = 0; i < 6; i++) k += Integer.parseInt(st.nextToken());
            while (true) {
                if (k > n) break;
                k *= 4;
                d++;
            }
            sb.append(d + "\n");
        }
        System.out.println(sb);
    }
}
