import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long k = Long.parseLong(br.readLine()) - 1;
        int cnt = 0;
        int t = (int) (Math.log(k) / Math.log(2));
        long tmp = 1L << t;
        while (t-- > 0) {
            if (k >= tmp) cnt++;
            k %= tmp;
            tmp >>= 1;
        }
        System.out.println((k + cnt) % 2);
    }
}
