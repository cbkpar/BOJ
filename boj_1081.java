import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long a = Integer.parseInt(st.nextToken());
        if (a == 0) a++;
        long b = Integer.parseInt(st.nextToken());
        long t = 1;
        long ans = 0;
        while (true) {
            while (a % 10 != 0 && a <= b) ans += calc(a++) * t;
            if (a > b) break;
            while (b % 10 != 9 && a <= b) ans += calc(b--) * t;
            ans += (b / 10 - a / 10 + 1) * 45 * t;
            t *= 10;
            a /= 10;
            b /= 10;
        }
        System.out.println(ans);
    }

    private static long calc(long n) {
        long tmp = 0;
        while (n > 0) {
            tmp += n % 10;
            n /= 10;
        }
        return tmp;
    }
}
