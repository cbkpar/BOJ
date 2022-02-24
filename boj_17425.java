import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        long[] f = new long[1000001];
        long[] g = new long[1000001];
        for (int i = 1; i <= 1000000; i++) {
            for (int j = i; j <= 1000000; j += i) {
                f[j] += i;
            }
            g[i] = g[i - 1] + f[i];
        }
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            sb.append(g[n] + "\n");
        }
        System.out.println(sb);
    }
}
