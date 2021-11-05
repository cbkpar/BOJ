import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int odd = 0;
        int even = 0;
        for (int i = 0; i < n; i++) {
            if (Integer.parseInt(st.nextToken()) % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        int mx = 0;
        while (odd >= 0) {
            if (even > odd) mx = Math.max(mx, 2 * odd + 1);
            if (even == odd) mx = Math.max(mx, 2 * odd);
            odd -= 2;
            even += 1;
        }
        System.out.println(mx);
    }
}
