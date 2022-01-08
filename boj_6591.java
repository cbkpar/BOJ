import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            if (n == 0) break;
            if (k > n / 2) k = n - k;
            BigInteger A = new BigInteger("1");
            BigInteger B = new BigInteger("1");
            for (int i = 0; i < k; i++) {
                A = A.multiply(new BigInteger(Integer.toString(n - i)));
                B = B.multiply(new BigInteger(Integer.toString(i + 1)));
            }
            sb.append(A.divide(B) + "\n");
        }
        System.out.println(sb);
    }
}
