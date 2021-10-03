import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long t, n;
        int k;
        k = 1;
        n = Long.parseLong(br.readLine());
        t = 3;
        while (true) {
            if (n <= t) break;
            t = t * 2 + k + 3;
            k++;
        }
        while (true) {
            if (k == 1) {
                System.out.println(n == 1 ? "m" : "o");
                return;
            }
            t = (t - k - 2) / 2;
            if (n <= t) {
            } else if (n <= t + k + 2) {
                System.out.println(n == t + 1 ? "m" : "o");
                return;
            } else {
                n -= t + k + 2;
            }
            k--;
        }
    }
}
