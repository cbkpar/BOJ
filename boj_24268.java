import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int ans = -1;
    static int n, d;
    static boolean[] chk;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        chk = new boolean[d];
        for (int i = 1; i < d; i++) {
            chk[i] = true;
            btr(1, i);
            chk[i] = false;
        }
        System.out.println(ans);
    }

    private static void btr(int k, int sum) {
        if (ans != -1) return;
        if (k == d) {
            if (sum > n) ans = sum;
            return;
        }
        for (int i = 0; i < d; i++) {
            if (!chk[i]) {
                chk[i] = true;
                btr(k + 1, sum * d + i);
                chk[i] = false;
            }
        }
    }
}
