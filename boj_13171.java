import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final long MOD = 1000000007;
        long A = Long.parseLong(br.readLine()) % MOD;
        long X = Long.parseLong(br.readLine());
        long ans = 1;
        while (X > 0) {
            if (X % 2 == 1) {
                ans = (ans * A) % MOD;
            }
            X >>= 1;
            A = (A * A) % MOD;
        }
        System.out.println(ans);
    }
}
