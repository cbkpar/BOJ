import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        System.out.println(calcmove(n, m));
    }

    private static int calcmove(int n, int m) {
        n = Math.abs(n);
        m = Math.abs(m);
        if (n == 0 && m == 0) return 0;
        if (n <= 1 && m <= 1) return 1;
        if (n == 1 || m == 1) return 1;
        if (n == 0 || m == 0) return 2;
        int g = gcd(n, m);
        if (g == 1) return 1;
        return 2;
    }

    private static int gcd(int a, int b) {
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }
}
