import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static long[] arr = new long[10];
    static long t;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int a = 1;
        int b = Integer.parseInt(br.readLine());
        t = 1;
        while (true) {
            while (a % 10 != 0 && a <= b) {
                calc(a);
                a++;
            }
            if(a>b) break;
            while (b % 10 != 9 && a <= b) {
                calc(b);
                b--;
            }
            for (int i = 0; i < 10; i++) arr[i] += (b / 10 - a / 10 + 1) * t;
            t *= 10;
            a /= 10;
            b /= 10;
        }
        for (int i = 0; i < 10; i++) sb.append(arr[i] + " ");
        System.out.println(sb);
    }

    public static void calc(int n) {
        while (n > 0) {
            arr[n % 10] += t;
            n /= 10;
        }
    }
}
