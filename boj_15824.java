import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        final long MOD = 1000000007;
        long[] arr = new long[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) arr[i] = Long.parseLong(st.nextToken());
        Arrays.sort(arr);
        long plus = 0;
        long minus = 0;
        long tmp = 0;
        long add = 1;
        for (int i = 1; i < n; i++) {
            tmp = (tmp + add) % MOD;
            plus = (plus + tmp * arr[i]) % MOD;
            add = (add * 2) % MOD;
        }
        tmp = 0;
        add = 1;
        for (int i = n - 2; i >= 0; i--) {
            tmp = (tmp + add) % MOD;
            minus = (minus + tmp * arr[i]) % MOD;
            add = (add * 2) % MOD;
        }
        System.out.println((plus - minus + MOD) % MOD);
    }
}
