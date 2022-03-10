import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        long k = B - A - 1;
        if (k == -1) {
            System.out.println("0");
            return;
        }
        long n = (long) Math.sqrt(k);
        if (k >= n * n + n) {
            System.out.println(2 * n + 1);
        } else {
            System.out.println(2 * n);
        }
    }
}
