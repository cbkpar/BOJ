import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        BigDecimal big = new BigDecimal(st.nextToken());
        BigDecimal ans = new BigDecimal("1");
        int t = Integer.parseInt(st.nextToken());
        while (t > 0) {
            if (t % 2 == 1) {
                ans = ans.multiply(big);
            }
            big = big.pow(2);
            t /= 2;
        }
        System.out.println(ans.toPlainString());
    }
}
