import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int i = n / 2; i >= 1; i--) {
            if (gcd(i, n - i) == 1) {
                System.out.println(i + " " + (n - i));
                return;
            }
        }
    }

    private static int gcd(int a, int b) {
        if (b % a == 0) return a;
        return gcd(b % a, a);
    }
}
