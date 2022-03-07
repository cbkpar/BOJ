import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static final int MOD = 1000000007;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int m = Integer.parseInt(br.readLine());
        long ans = 0;
        while (m-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long n = Long.parseLong(st.nextToken());
            long s = Long.parseLong(st.nextToken());
            ans = (ans + mathpow(n, MOD - 2) * s) % MOD;
        }
        System.out.println(ans);
    }

    private static long mathpow(long n, int k) {
        long tmp = 1;
        while (k > 0) {
            if (k % 2 == 1) tmp = (tmp * n) % MOD;
            n = (n * n) % MOD;
            k /= 2;
        }
        return tmp;
    }
}
