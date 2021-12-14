import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        BigInteger big = new BigInteger("0");
        for (int i = 1; i < n; i++) {
            if (i % 2 == 0) {
                big = big.multiply(new BigInteger("2")).subtract(new BigInteger("1"));
            } else {
                big = big.multiply(new BigInteger("2")).add(new BigInteger("1"));
            }
        }
        System.out.println(big);
    }
}
