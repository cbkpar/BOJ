import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        long n, k, t;
        int i, d;
        n = Integer.parseInt(br.readLine());
        if (n == 0) {
            System.out.println("0");
            return;
        }
        boolean flag = false;
        if (n < 0) flag = true;
        k = 1;
        n = Math.abs(n);
        Stack<Integer> s = new Stack<>();
        d = 0;
        while (true) {
            if (n <= k) {
                n--;
                for (i = 0; i < d; i++) {
                    s.add((int) (n % 3));
                    n/=3;
                }
                s.add(2);
                break;
            }
            t = n % (k * 3) / k;
            n -= k;
            k *= 3;
            d++;
        }
        while (!s.isEmpty()) {
            t = s.pop();
            if (!flag) {
                if (t == 0) {
                    sb.append("T");
                } else if (t == 1) {
                    sb.append("0");
                } else if (t == 2) {
                    sb.append("1");
                }
            } else {
                if (t == 0) {
                    sb.append("1");
                } else if (t == 1) {
                    sb.append("0");
                } else if (t == 2) {
                    sb.append("T");
                }
            }
        }
        System.out.println(sb);
    }
}
