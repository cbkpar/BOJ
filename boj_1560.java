import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        if (str.equals("1")) {
            System.out.println("1");
            return;
        }
        BigInteger bigInt = new BigInteger(str);
        bigInt = bigInt.subtract(BigInteger.ONE);
        bigInt = bigInt.multiply(BigInteger.valueOf(2));
        System.out.println(bigInt);
    }
}
