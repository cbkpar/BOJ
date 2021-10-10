import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine()) - 1;
        StringTokenizer st = new StringTokenizer(br.readLine());
        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong(st.nextToken());
        long g = a > b ? gcd(b, a) : gcd(a, b);
        a /= g;
        b /= g;
        while (n-- > 0) {
            st = new StringTokenizer(br.readLine());
            long c = Long.parseLong(st.nextToken());
            long d = Long.parseLong(st.nextToken());
            g = c > d ? gcd(d, c) : gcd(c, d);
            c /= g;
            d /= g;
            a = a > c ? gcd(c, a) : gcd(a, c);
            g = b > d ? gcd(d, b) : gcd(b, d);
            d /= g;
            b = b * d;
        }

        g = a > b ? gcd(b, a) : gcd(a, b);
        a /= g;
        b /= g;
        System.out.println(a + " " + b);
    }

    private static long gcd(long a, long b) {
        if (b % a == 0) return a;
        return gcd(b % a, a);
    }
}
