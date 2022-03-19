import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int p = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        boolean[][] chk = new boolean[q + 1][q + 1];
        int ans = 0;
        for (int i = p; i <= q; i++) {
            for (int j = 1; j <= i; j++) {
                int g = gcd(i, j);
                int a = i / g;
                int b = j / g;
                if (chk[a][b]) continue;
                chk[a][b] = true;
                ans++;
            }
        }
        System.out.println(ans);
    }

    private static int gcd(int a, int b) {
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }
}
